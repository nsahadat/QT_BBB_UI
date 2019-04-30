#include "train.h"
#include "ui_train.h"

Train::Train(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Train)
{
    ui->setupUi(this);

    QDir dir;
 //   qDebug() << dir.currentPath();
    if (!dir.exists(dir.currentPath() + "/TDS"))
    {
        dir.mkdir("TDS");
    }
    trainfilename = dir.currentPath();

    // add the initial training pic
    QPixmap initial((trainfilename + "/IMG/initial.PNG").toUtf8().constData());
    ui->TPic->setPixmap(initial);

    // progress bar setup
    // UI progressBar overall
    ui->progBarAll->setMinimum(0);
    ui->progBarAll->setMaximum(20);

    // UI progressBar size
    ui->progBarEach->setMinimum(0);
    ui->progBarEach->setMaximum(999);

    // setup the COM ports for the data collection
    findPort();
    sd = new sensdata(source, this);
    sd->sensdata :: setPortTDS();  //data 0; command 1; model 2
    sd->setPortdatacmdmodel(0);


    // connect signals and slots
    connect(sd, SIGNAL(newData()), this, SLOT(SaveData()));
    connect(sd, SIGNAL(newModel()), this, SLOT(modelreceived()));
    connect(this, SIGNAL(dataSaved()), this, SLOT(changePic()));



}

Train::~Train()
{
    datafileout.close();
    delete ui;
}

void Train::on_ButtonStart_clicked()
{
    QPixmap nc((trainfilename + "/IMG/nc.PNG").toUtf8().constData());
    ui->TPic->setPixmap(nc);


}

void Train::on_ButtonExit_clicked()
{
    close();

    // debugging
    //QString str;
    //sd->readCharacters();
    //str.append(sd->msg);
    //qDebug() << str;

    //qDebug() << sd->msg;

}

void Train::findPort(void)
{
    QList<QSerialPortInfo> serialPorts = QSerialPortInfo::availablePorts();
    //QSerialPort serialPort;

    for (QSerialPortInfo port : serialPorts)
    {

        if (port.productIdentifier() == 60000)
        {
            source = QString("%1").arg(port.portName());
        //    qDebug() << "mTDS found" << endl;

        }

    }

}

void Train::OpenFile(char *filename)
{
    datafileout.open(filename);
}

void Train::SaveData(void)
{

   if (dataCounter < 1000)
   {

       sd->reqData();
       for (uint8_t i = 0; i < (SENS_PKT_SIZE - 6); i++)
       {
           datafileout << (float)(sd->senData [i])* 0.000305 << " ";
           //qDebug() << QString::number(sd->senData [i]);

       }

       datafileout << "\n";

       ui->progBarEach->setValue(dataCounter);

       dataCounter++;
   }

   else
   {
        datafileout.close();
        ui->progBarAll->setValue(round*7 + command);
        emit dataSaved();
   }




}


void Train::modelreceived()
{
    //modelrcv = true;
    char sendbuff[MODEL_PKT_SIZE+1];
    float sentvalue, rcvvalue;

    bool success = false;

    if (pktsent < 6) //20)//35)
    {


        for(int c = 0; c<MODEL_PKT_SIZE; c++)
        {
            if (pktsent < 5)//34)
            {
                sendbuff[c+1] = trbuff[pktsent*MODEL_PKT_SIZE + c];
            }
            else
            {
                if (c< 196) //12)       // change according to packet size
                {
                    sendbuff[c+1] = trbuff[pktsent*MODEL_PKT_SIZE + c];
                }
                else
                {
                    sendbuff[c+1] = 0;
                }

            }

        }
        sendbuff[0] = pktsent;

        sd->writeData(sendbuff, MODEL_PKT_SIZE+1);        // sending data


        for (int i=1; i<(MODEL_PKT_SIZE+1); i = i+4)
        {

            fu.fBuff[0] = sendbuff[i + 0];
            fu.fBuff[1] = sendbuff[i + 1];
            fu.fBuff[2] = sendbuff[i + 2];
            fu.fBuff[3] = sendbuff[i + 3];


            sentvalue = fu.f;

            // received packet

            fu.fBuff[0] = sd->pktModel[i + 0];
            fu.fBuff[1] = sd->pktModel[i + 1];
            fu.fBuff[2] = sd->pktModel[i + 2];
            fu.fBuff[3] = sd->pktModel[i + 3];

            rcvvalue = fu.f;

            // data checking
            if (sentvalue == rcvvalue)
            {
                success = true;
            }
            else
            {
                success = false;
            }

            //qDebug() << "send : received" ;
            qDebug() <<QString::number(pktsent) << ":" <<QString::number(sentvalue) << ":" << QString::number(rcvvalue);

        }

        qDebug() <<"Packet number sent : received"<<QString::number(sendbuff[0]) << ":" <<QString::number(sd->pktModel[0]) ;

        if (success)
        {
            pktsent++; // debug
            success = false;
        }

    }
    else
    {
        sendbuff[0] = 6;
        sd->writeData(sendbuff, MODEL_PKT_SIZE+1);
        ui->status->setText("Transfer Done!");
        sd->setPortdatacmdmodel(1);     // debugging characters read
    }

}



void Train::on_ButtonCollect_clicked()
{
    //sd->setPortdatacmdmodel(0);
    QString filename;



            switch (command)
            {
            case 0:
                //sprintf(filename,"D:/Google Drive/GATech/standalone TDS/QTApps/TDS/nc_%d.txt",round);
                filename = (trainfilename + "/TDS/"+"nc_" + QString::number(round) + ".txt");
                break;
            case 1:
                //sprintf(filename,"D:/Google Drive/GATech/standalone TDS/QTApps/TDS/left_%d.txt",round);
                filename = (trainfilename + "/TDS/"+"left_" + QString::number(round) + ".txt");
                break;
            case 2:
                //sprintf(filename,"D:/Google Drive/GATech/standalone TDS/QTApps/TDS/right_%d.txt",round);
                filename = (trainfilename + "/TDS/"+"right_" + QString::number(round) + ".txt");
                break;
            case 3:
                //sprintf(filename,"D:/Google Drive/GATech/standalone TDS/QTApps/TDS/up_%d.txt",round);
                filename = (trainfilename + "/TDS/"+"up_" + QString::number(round) + ".txt");
                break;
            case 4:
                //sprintf(filename,"D:/Google Drive/GATech/standalone TDS/QTApps/TDS/down_%d.txt",round);
                filename = (trainfilename + "/TDS/"+"down_" + QString::number(round) + ".txt");
                break;
            case 5:
                //sprintf(filename,"D:/Google Drive/GATech/standalone TDS/QTApps/TDS/ls_%d.txt",round);
                filename = (trainfilename + "/TDS/"+"ls_" + QString::number(round) + ".txt");
                break;
            case 6:
                //sprintf(filename,"D:/Google Drive/GATech/standalone TDS/QTApps/TDS/rs_%d.txt",round);
                filename = (trainfilename + "/TDS/"+"rs_" + QString::number(round) + ".txt");
                break;
            }
            datafileout.open(filename.toUtf8().constData());
            dataCounter = 0;
           // OpenFile(filename.toUtf8().constData());
            sd->reqData();

}

void Train::changePic(void)
{
    QPixmap initial((trainfilename + "/IMG/initial.PNG").toUtf8().constData());
    QPixmap nc((trainfilename + "/IMG/nc.PNG").toUtf8().constData());
    QPixmap left((trainfilename + "/IMG/left.PNG").toUtf8().constData());
    QPixmap right((trainfilename + "/IMG/right.PNG").toUtf8().constData());
    QPixmap up((trainfilename + "/IMG/up.PNG").toUtf8().constData());
    QPixmap down((trainfilename + "/IMG/down.PNG").toUtf8().constData());
    QPixmap ls((trainfilename + "/IMG/ls.PNG").toUtf8().constData());
    QPixmap rs((trainfilename + "/IMG/rs.PNG").toUtf8().constData());

    switch (command)
    {
    case 0:
        ui->TPic->setPixmap(left);
        command = 1;
        break;
    case 1:
        ui->TPic->setPixmap(right);
        command = 2;
        break;
    case 2:
        ui->TPic->setPixmap(up);
        command = 3;
        break;
    case 3:
        ui->TPic->setPixmap(down);
        command = 4;
        break;
    case 4:
        ui->TPic->setPixmap(ls);
        command = 5;
        break;
    case 5:
        ui->TPic->setPixmap(rs);
        command = 6;
        break;
    case 6:

        command = 0;
        round++;

        if (round <3)
        {
            ui->TPic->setPixmap(nc);
        }
        else
        {
            ui->TPic->setPixmap(initial);
        }
        break;
    }
   // dataCounter = 0;
}

void Train::on_ButtonTrain_clicked()
{

    mat temp0,temp1,temp2, left, right, up, down, ls, rs, nc;

    ofstream lt;

    cdata = zeros(1000,15);
    proj1 = zeros(4,3);
    proj2 = zeros(4,3);
    proj3 = zeros(4,3);
    proj4 = zeros(4,3);

    proj1.load((trainfilename + "/TDS/proj1.txt").toUtf8().constData()); // open proj1
    proj2.load((trainfilename + "/TDS/proj2.txt").toUtf8().constData()); // open proj2
    proj3.load((trainfilename + "/TDS/proj3.txt").toUtf8().constData()); // open proj3
    proj4.load((trainfilename + "/TDS/proj4.txt").toUtf8().constData()); // open proj4

    // find cal projected matrixes

    // left
    cdata.load((trainfilename + "/TDS/left_0.txt").toUtf8().constData());
    removeEMF();
    temp0 = cfeature;

    cdata.load((trainfilename + "/TDS/left_1.txt").toUtf8().constData());
    removeEMF();
    temp1 = cfeature;

    left = join_vert(temp0,temp1);

    cdata.load((trainfilename + "/TDS/left_2.txt").toUtf8().constData());
    removeEMF();
    temp2 = cfeature;

    left =  join_vert(left,temp2);

    lt.open((trainfilename + "/TDS/leftC.txt").toUtf8().constData());
    lt << left;
    lt.close();

    // right
    cdata.load((trainfilename + "/TDS/right_0.txt").toUtf8().constData());
    removeEMF();
    temp0 = cfeature;

    cdata.load((trainfilename + "/TDS/right_1.txt").toUtf8().constData());
    removeEMF();
    temp1 = cfeature;

    right = join_vert(temp0,temp1);

    cdata.load((trainfilename + "/TDS/right_2.txt").toUtf8().constData());
    removeEMF();
    temp2 = cfeature;

    right =  join_vert(right,temp2);

    lt.open((trainfilename + "/TDS/rightC.txt").toUtf8().constData());
    lt << right;
    lt.close();

    // up
    cdata.load((trainfilename + "/TDS/up_0.txt").toUtf8().constData());
    removeEMF();
    temp0 = cfeature;

    cdata.load((trainfilename + "/TDS/up_1.txt").toUtf8().constData());
    removeEMF();
    temp1 = cfeature;

    up = join_vert(temp0,temp1);

    cdata.load((trainfilename + "/TDS/up_2.txt").toUtf8().constData());
    removeEMF();
    temp2 = cfeature;

    up =  join_vert(up,temp2);

    lt.open((trainfilename + "/TDS/upC.txt").toUtf8().constData());
    lt << up;
    lt.close();

    // down
    cdata.load((trainfilename + "/TDS/down_0.txt").toUtf8().constData());
    removeEMF();
    temp0 = cfeature;

    cdata.load((trainfilename + "/TDS/down_1.txt").toUtf8().constData());
    removeEMF();
    temp1 = cfeature;

    down = join_vert(temp0,temp1);

    cdata.load((trainfilename + "/TDS/down_2.txt").toUtf8().constData());
    removeEMF();
    temp2 = cfeature;

    down =  join_vert(down,temp2);

    lt.open((trainfilename + "/TDS/downC.txt").toUtf8().constData());
    lt << down;
    lt.close();

    // ls
    cdata.load((trainfilename + "/TDS/ls_0.txt").toUtf8().constData());
    removeEMF();
    temp0 = cfeature;

    cdata.load((trainfilename + "/TDS/ls_1.txt").toUtf8().constData());
    removeEMF();
    temp1 = cfeature;

    ls = join_vert(temp0,temp1);

    cdata.load((trainfilename + "/TDS/ls_2.txt").toUtf8().constData());
    removeEMF();
    temp2 = cfeature;

    ls =  join_vert(ls,temp2);


    lt.open((trainfilename + "/TDS/lsC.txt").toUtf8().constData());
    lt << ls;
    lt.close();

    // rs
    cdata.load((trainfilename + "/TDS/rs_0.txt").toUtf8().constData());
    removeEMF();
    temp0 = cfeature;

    cdata.load((trainfilename + "/TDS/rs_1.txt").toUtf8().constData());
    removeEMF();
    temp1 = cfeature;

    rs = join_vert(temp0,temp1);

    cdata.load((trainfilename + "/TDS/rs_2.txt").toUtf8().constData());
    removeEMF();
    temp2 = cfeature;

    rs =  join_vert(rs,temp2);

    lt.open((trainfilename + "/TDS/rsC.txt").toUtf8().constData());
    lt << rs;
    lt.close();

    // nc
    cdata.load((trainfilename + "/TDS/nc_0.txt").toUtf8().constData());
    removeEMF();
    temp0 = cfeature;

    cdata.load((trainfilename + "/TDS/nc_1.txt").toUtf8().constData());
    removeEMF();
    temp1 = cfeature;

    nc = join_vert(temp0,temp1);

    cdata.load((trainfilename + "/TDS/nc_2.txt").toUtf8().constData());
    removeEMF();
    temp2 = cfeature;

    nc =  join_vert(nc,temp2);

    lt.open((trainfilename + "/TDS/ncC.txt").toUtf8().constData());
    lt << nc;
    lt.close();

    // creating the SVM training format file for training

    char buff[200];
    ofstream tfile;
    tfile.open((trainfilename + "/TDS/training.txt").toUtf8().constData());
    int r=0;

    for (r = 0; r<3000; r++)
    {
        sprintf(buff, "0 1:%f 2:%f 3:%f 4:%f 5:%f 6:%f 7:%f 8:%f 9:%f 10:%f 11:%f 12:%f\n"
                ,nc(r,0),nc(r,1),nc(r,2),nc(r,3),nc(r,4),nc(r,5),nc(r,6),nc(r,7),nc(r,8),nc(r,9),nc(r,10),nc(r,11));

        tfile << buff;
    }

    r = 0;
    for (r = 0; r<3000; r++)
    {
        sprintf(buff, "1 1:%f 2:%f 3:%f 4:%f 5:%f 6:%f 7:%f 8:%f 9:%f 10:%f 11:%f 12:%f\n"
                ,left(r,0),left(r,1),left(r,2),left(r,3),left(r,4),left(r,5),left(r,6),left(r,7),left(r,8),left(r,9),left(r,10),left(r,11));

        tfile << buff;
    }

    r = 0;
    for (r = 0; r<3000; r++)
    {
        sprintf(buff, "2 1:%f 2:%f 3:%f 4:%f 5:%f 6:%f 7:%f 8:%f 9:%f 10:%f 11:%f 12:%f\n"
                ,right(r,0),right(r,1),right(r,2),right(r,3),right(r,4),right(r,5),right(r,6),right(r,7),right(r,8),right(r,9),right(r,10),right(r,11));

        tfile << buff;
    }

    r = 0;
    for (r = 0; r<3000; r++)
    {
        sprintf(buff, "3 1:%f 2:%f 3:%f 4:%f 5:%f 6:%f 7:%f 8:%f 9:%f 10:%f 11:%f 12:%f\n"
                ,up(r,0),up(r,1),up(r,2),up(r,3),up(r,4),up(r,5),up(r,6),up(r,7),up(r,8),up(r,9),up(r,10),up(r,11));

        tfile << buff;
    }

    r = 0;
    for (r = 0; r<3000; r++)
    {
        sprintf(buff, "4 1:%f 2:%f 3:%f 4:%f 5:%f 6:%f 7:%f 8:%f 9:%f 10:%f 11:%f 12:%f\n"
                ,down(r,0),down(r,1),down(r,2),down(r,3),down(r,4),down(r,5),down(r,6),down(r,7),down(r,8),down(r,9),down(r,10),down(r,11));

        tfile << buff;
    }

    r = 0;
    for (r = 0; r<3000; r++)
    {
        sprintf(buff, "5 1:%f 2:%f 3:%f 4:%f 5:%f 6:%f 7:%f 8:%f 9:%f 10:%f 11:%f 12:%f\n"
                ,ls(r,0),ls(r,1),ls(r,2),ls(r,3),ls(r,4),ls(r,5),ls(r,6),ls(r,7),ls(r,8),ls(r,9),ls(r,10),ls(r,11));

        tfile << buff;
    }

    r = 0;
    for (r = 0; r<3000; r++)
    {
        sprintf(buff, "6 1:%f 2:%f 3:%f 4:%f 5:%f 6:%f 7:%f 8:%f 9:%f 10:%f 11:%f 12:%f\n"
                ,rs(r,0),rs(r,1),rs(r,2),rs(r,3),rs(r,4),rs(r,5),rs(r,6),rs(r,7),rs(r,8),rs(r,9),rs(r,10),rs(r,11));

        tfile << buff;
    }


    tfile.close();


    // training file creation done

    // lets train SVM

    mTDS_train((trainfilename + "/TDS/training.txt").toUtf8().constData(),
               (trainfilename + "/TDS/model.txt").toUtf8().constData(),
               (trainfilename + "/TDS/B.txt").toUtf8().constData(),
               (trainfilename + "/TDS/coeff.txt").toUtf8().constData(),
               (trainfilename + "/TDS/SV.txt").toUtf8().constData(),
               (trainfilename + "/TDS/nSV.txt").toUtf8().constData());

     CalW(); // Let's generate W and B matrixes and create a parameter text file

      ui->status->setText("Training Done!");

}


void Train::removeEMF(void)
{
    cfeature = zeros(1000,12);

    cfeature.cols(0,2) = cdata.cols(0,2) - (cdata.cols(12,14) * proj1.rows(1,3) + ones(1000,1)* proj1.row(0));
    cfeature.cols(3,5) = cdata.cols(3,5) - (cdata.cols(12,14) * proj2.rows(1,3) + ones(1000,1)* proj2.row(0));
    cfeature.cols(6,8) = cdata.cols(6,8) - (cdata.cols(12,14) * proj3.rows(1,3) + ones(1000,1)* proj3.row(0));
    cfeature.cols(9,11) = cdata.cols(9,11) - (cdata.cols(12,14) * proj4.rows(1,3) + ones(1000,1)* proj4.row(0));

}


// read in a problem (in svmlight format)

void Train::read_problem(const char *filename)
{
    int max_index, inst_max_index, i;
    size_t elements, j;
    FILE *fp = fopen(filename, "r");
    char *endptr;
    char *idx, *val, *label;

    if (fp == NULL)
    {
        fprintf(stderr, "can't open input file %s\n", filename);
        exit(1);
    }

    prob.l = 0;
    elements = 0;

    max_line_len = 1024;
    line = Malloc(char, max_line_len);
    while (readline(fp) != NULL)
    {
        char *p = strtok(line, " \t"); // label

        // features
        while (1)
        {
            p = strtok(NULL, " \t");
            if (p == NULL || *p == '\n') // check '\n' as ' ' may be after the last feature
                break;
            ++elements;
        }
        ++elements;
        ++prob.l;
    }
    rewind(fp);

    prob.y = Malloc(double, prob.l);
    prob.x = Malloc(struct svm_node *, prob.l);
    x_space = Malloc(struct svm_node, elements);

    max_index = 0;
    j = 0;
    for (i = 0; i<prob.l; i++)
    {
        inst_max_index = -1; // strtol gives 0 if wrong format, and precomputed kernel has <index> start from 0
        readline(fp);
        prob.x[i] = &x_space[j];
        label = strtok(line, " \t\n");
        if (label == NULL) // empty line
            exit_input_error(i + 1);

        prob.y[i] = strtod(label, &endptr);
        if (endptr == label || *endptr != '\0')
            exit_input_error(i + 1);

        while (1)
        {
            idx = strtok(NULL, ":");
            val = strtok(NULL, " \t");

            if (val == NULL)
                break;

            errno = 0;
            x_space[j].index = (int)strtol(idx, &endptr, 10);
            if (endptr == idx || errno != 0 || *endptr != '\0' || x_space[j].index <= inst_max_index)
                exit_input_error(i + 1);
            else
                inst_max_index = x_space[j].index;

            errno = 0;
            x_space[j].value = strtod(val, &endptr);
            if (endptr == val || errno != 0 || (*endptr != '\0' && !isspace(*endptr)))
                exit_input_error(i + 1);

            ++j;
        }

        if (inst_max_index > max_index)
            max_index = inst_max_index;
        x_space[j++].index = -1;
    }

    if (param.gamma == 0 && max_index > 0)
        param.gamma = 1.0 / max_index;

    if (param.kernel_type == PRECOMPUTED)
        for (i = 0; i<prob.l; i++)
        {
            if (prob.x[i][0].index != 0)
            {
                fprintf(stderr, "Wrong input format: first column must be 0:sample_serial_number\n");
                exit(1);
            }
            if ((int)prob.x[i][0].value <= 0 || (int)prob.x[i][0].value > max_index)
            {
                fprintf(stderr, "Wrong input format: sample_serial_number out of range\n");
                exit(1);
            }
        }

    fclose(fp);
}

char* Train::readline(FILE *input)
{
    int len;

    if (fgets(line, max_line_len, input) == NULL)
        return NULL;

    while (strrchr(line, '\n') == NULL)
    {
        max_line_len *= 2;
        line = (char *)realloc(line, max_line_len);
        len = (int)strlen(line);
        if (fgets(line + len, max_line_len - len, input) == NULL)
            break;
    }
    return line;
}

void Train:: mTDS_train(const char *input_file_name,  const char *model_file_name, const char *Bfile, const char *Coefffile, const char *SVfile, const char *nSVfile)
{
    const char *error_msg;

    // SVM parameters
    param.svm_type = C_SVC;  //NU_SVC;
    param.kernel_type = LINEAR;  //RBF;
    param.degree = 3;
    param.gamma = 0.000001; //gamm; // 0.000001;	// 1/num_features
    param.coef0 = 0;
    param.nu = 0.5;
    param.cache_size = 100;
    param.C = 1;
    param.eps = 1e-3;
    param.p = 0.1;
    param.shrinking = 0;
    param.probability = 0;
    param.nr_weight = 0;
    param.weight_label = NULL;
    param.weight = NULL;
    cross_validation = 0;

    //parse_command_line(argc, argv, input_file_name, model_file_name);
    read_problem(input_file_name);
    error_msg = svm_check_parameter(&prob, &param);

    if (error_msg)
    {
        fprintf(stderr, "ERROR: %s\n", error_msg);
        exit(1);
    }

    model = svm_train(&prob, &param);
    if (svm_save_model(model_file_name, model))
    {
        fprintf(stderr, "can't save model to file %s\n", model_file_name);
        exit(1);
    }

    svm_save_W_b(Bfile, Coefffile, SVfile, nSVfile, model);
}


void Train::svm_save_W_b(const char *Bfile, const char *Coefffile, const char *SVfile, const char *nSVfile, const svm_model *model)
//int svm_save_W_b(const char *W, const char *B, const svm_model *model)
{

    int nr_class = model->nr_class;
    int l = model->l;

    //generate a file with Beta
    datafileout.open(Bfile);

    for (int i = 0; i < nr_class*(nr_class - 1) / 2; i++)
    {
        datafileout << model->rho[i];

        if (i < (nr_class*(nr_class - 1) / 2) - 1)
            datafileout << " ";
    }
    datafileout.close();


    //fB << endl;
    datafileout.open(nSVfile);
    for (int i = 0; i < nr_class; i++)
    {
        datafileout << model->nSV[i];

        if (i < (nr_class - 1))
            datafileout << " ";
    }
    datafileout.close();

    //fnSV << endl;


    const double * const *sv_coef = model->sv_coef;
    const svm_node * const *SV = model->SV;

    datafileout.open(Coefffile);

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < nr_class - 1; j++)
        {
            datafileout << sv_coef[j][i];

            if (j < nr_class - 2)
                datafileout << " ";
        }
        if (i < l - 1)
        {
            datafileout << "\n";
        }

    }

    datafileout.close();



    datafileout.open(SVfile);
    for (int i = 0; i<l; i++)
    {

        const svm_node *p = SV[i];
        //int k = 0;

        while (p->index != -1)
        {
            //fprintf(fW, "%d:%lf\t", p->index, p->value);
            //fprintf(fW, "%.16g\t", p->value);

            //fprintf(fW, "%f\t", p->value);
            datafileout << p->value;

            if (((p + 1)->index) != -1)
            {
                datafileout << " ";
            }

            p++;
        }
        if (i != l-1)
        {
            datafileout << "\n";
        }

    }

    datafileout.close();


}

void Train:: exit_input_error(int line_num)
{
    fprintf(stderr, "Wrong input format at line %d\n", line_num);
    exit(1);
}

void Train:: CalW(void)
{
    mat nSV, r1, r2;
    nSV.load((trainfilename + "/TDS/nSV.txt").toUtf8().constData());
    r1.zeros(1,nSV.n_cols);
    r2.zeros(1,nSV.n_cols);

   for (int i=0; i<nSV.n_cols; i++)
   {
        if (i == 0)
        {
            r1(0,i) = 0;
            r2(0,i) = nSV(0,0)-1;
        }
        else
        {
            r1(0,i) = r1(0,i-1) + nSV(0,i-1);
            r2(0,i) = r2(0,i-1) + nSV(0,i);
        }
     //   qDebug() << "r1: " << r1(0,i) << "r2: " << r2(0,i);
   }

// matlab
//    for i=1:length(nSV)
//        if i == 1
//            r1(i) = 1;
//            r2(i) = nSV(1);

//        else
//            r1(i) = r1(i - 1) + nSV(i-1);
//            r2(i) = r2(i-1) + nSV(i);
//        end
//    end

// conversion
   int k= 0; //    k = 1;
   mat w, SVs, Coeffs; //    w = [];
   w.zeros(12,21);      // initialize
   SVs.load((trainfilename + "/TDS/SV.txt").toUtf8().constData());
   Coeffs.load((trainfilename + "/TDS/coeff.txt").toUtf8().constData());

   for (int l = 0; l<6; l++)    //    for i = 1:6
   {
       for (int j = l+1; j<7; j++)
       {
           // w(:,k) = ([SVs(r1(i):r2(i),:);SVs(r1(j):r2(j),:)]' * [Coeffs(r1(i):r2(i),j-1);Coeffs(r1(j):r2(j),i)])';

           w.col(k) = trans(join_vert(SVs.rows(r1(0,l),r2(0,l)),SVs.rows(r1(0,j),r2(0,j)))) * join_vert(Coeffs(span(r1(l),r2(l)),j-1),Coeffs(span(r1(j),r2(j)),l));
           k = k+1;

       }
   }

   datafileout.open((trainfilename + "/TDS/W.txt").toUtf8().constData());
   datafileout << w;
   datafileout.close();

   //        for j = i+1:7
   //            cij = [Coeffs(r1(i):r2(i),j-1);Coeffs(r1(j):r2(j),i)];
   //            wij = [SVs(r1(i):r2(i),:);SVs(r1(j):r2(j),:)]' * cij;
   //            w(:,k) =  wij';

   // w(:,k) = ([SVs(r1(i):r2(i),:);SVs(r1(j):r2(j),:)]' * [Coeffs(r1(i):r2(i),j-1);Coeffs(r1(j):r2(j),i)])';

   //             k = k + 1;
   //        end
   //    end

    mat B,prj1,prj2,prj3,prj4, Bt;
    mat prj;
    B.load((trainfilename + "/TDS/B.txt").toUtf8().constData());
    prj1.load((trainfilename + "/TDS/proj1.txt").toUtf8().constData());
    prj2.load((trainfilename + "/TDS/proj2.txt").toUtf8().constData());
    prj3.load((trainfilename + "/TDS/proj3.txt").toUtf8().constData());
    prj4.load((trainfilename + "/TDS/proj4.txt").toUtf8().constData());

  //  qDebug() << prj1.n_rows;

    prj = join_horiz(prj1.row(0),prj2.row(0));
    prj = join_horiz(prj,prj3.row(0));
    prj = join_horiz(prj,prj4.row(0));

    //  qDebug() << prj.n_rows;

    Bt = prj*w + B;

    datafileout.open((trainfilename + "/TDS/Bt.txt").toUtf8().constData());
    datafileout << Bt;
    datafileout.close();

    // let's create a parametric file for CPP


    QString s;
    int r = 1;
    int c = 0;
    // b1
    for (r = 1; r<4 ; r++)
    {
        for (c = 0; c<3; c++)
        {
            if (r==1 && c == 0)
            {
                s = "float b1[9] = {";
                s = s + QString::number(prj1(r,c))+",";
            }
            else if (r == 3 && c == 2 )
            {
                s = s + QString::number(prj1(r,c)) + "};\n\n";
            }
            else
            {
                s = s + QString::number(prj1(r,c)) + ",";
            }

        }
    }

    r=1;
    c=0;
    // b2
    for (r = 1; r<4 ; r++)
    {
        for (c = 0; c<3; c++)
        {
            if (r==1 && c == 0)
            {
                s = s + "float b2[9] = {";
                s = s + QString::number(prj2(r,c))+",";
            }
            else if (r == 3 && c == 2 )
            {
                s = s + QString::number(prj2(r,c)) + "};\n\n";
            }
            else
            {
                s = s + QString::number(prj2(r,c)) + ",";
            }

        }
    }

    r=1;
    c=0;
    // b3
    for (r = 1; r<4 ; r++)
    {
        for (c = 0; c<3; c++)
        {
            if (r==1 && c == 0)
            {
                s = s + "float b3[9] = {";
                s = s + QString::number(prj3(r,c))+",";
            }
            else if (r == 3 && c == 2 )
            {
                s = s + QString::number(prj3(r,c)) + "};\n\n";
            }
            else
            {
                s = s + QString::number(prj3(r,c)) + ",";
            }

        }
    }

    r=1;
    c=0;
    // b4
    for (r = 1; r<4 ; r++)
    {
        for (c = 0; c<3; c++)
        {
            if (r==1 && c == 0)
            {
                s = s + "float b4[9] = {";
                s = s + QString::number(prj4(r,c))+",";
            }
            else if (r == 3 && c == 2 )
            {
                s = s + QString::number(prj4(r,c)) + "};\n\n";
            }
            else
            {
                s = s + QString::number(prj4(r,c)) + ",";
            }

        }
    }


    r=0;
    c=0;
    // Bt
    for (r = 0; r<1 ; r++)
    {
        for (c = 0; c<21; c++)
        {
            if (r==0 && c == 0)
            {
                s = s + "float Beta[21] = {";
                s = s + QString::number(Bt(r,c))+",";
            }
            else if (r == 0 && c == 20 )
            {
                s = s + QString::number(Bt(r,c)) + "};\n\n";
            }
            else
            {
                s = s + QString::number(Bt(r,c)) + ",";
            }

        }
    }

    r=0;
    c=0;
    // W
    for (r = 0; r<12 ; r++)
    {
        for (c = 0; c<21; c++)
        {
            if (r==0 && c == 0)
            {
                s = s + "float W[12][21] = {{";
                s = s + QString::number(w(r,c))+",";
            }
            else if (r == 11 && c == 20 )
            {
                s = s + QString::number(w(r,c)) + "}};\n\n";
            }
            else if (r != 11 && c == 20 )
            {
                s = s + QString::number(w(r,c)) + "},\n";
            }
            else if (r != 0 && c == 0 )
            {
                s = s + "{" + QString::number(w(r,c)) + ",";
            }
            else
            {
                s = s + QString::number(w(r,c)) + ",";
            }

        }
    }


    datafileout.open((trainfilename + "/TDS/parameter.txt").toUtf8().constData());
    datafileout << s.toUtf8().constData();
    datafileout.close();

}

void Train::loadBuffer(void)
{
    mat Bt, W, prj1, prj2, prj3, prj4;

    Bt.load((trainfilename + "/TDS/Bt.txt").toUtf8().constData());
    W.load((trainfilename + "/TDS/W.txt").toUtf8().constData());
    prj1.load((trainfilename + "/TDS/proj1.txt").toUtf8().constData());
    prj2.load((trainfilename + "/TDS/proj2.txt").toUtf8().constData());
    prj3.load((trainfilename + "/TDS/proj3.txt").toUtf8().constData());
    prj4.load((trainfilename + "/TDS/proj4.txt").toUtf8().constData());


//    union FU {
//        float f;
//        char fBuff[sizeof(float)];
//    }fu;

    // convert proj1
    //char prjbuff[36];



    int indx = 0;

   // qDebug() << "Proj1";
    for (int r = 1; r<prj1.n_rows;r++)
    {
        for (int c = 0; c<prj1.n_cols; c++)
        {
            fu.f = prj1(r,c);
            for(int i=0;i<sizeof(float);i++)
            {
                //prjbuff[((r-1)*3 + c)*4 + i] =  fu.fBuff[i];
                trbuff[indx++] =  fu.fBuff[i];
            //    qDebug() << QString::number(prj1(r,c)) << ":" << QString::number(prjbuff[((r-1)*3 + c)*4 + i]);
            }
        }
    }

    // transfer proj1



    // convert proj2
   // char prjbuff[36];
  //  qDebug() << "Proj2";
    for (int r = 1; r<prj2.n_rows;r++)
    {
        for (int c = 0; c<prj2.n_cols; c++)
        {
            fu.f = prj2(r,c);
            for(int i=0;i<sizeof(float);i++)
            {
             //   prjbuff[((r-1)*3 + c)*4 + i] =  fu.fBuff[i];
                trbuff[indx++] =  fu.fBuff[i];
            //    qDebug() << QString::number(prj2(r,c)) << ":" << QString::number(prjbuff[((r-1)*3 + c)*4 + i]);
            }
        }
    }

    // transfer proj2


    // convert proj3
   // char prjbuff[36];
   // qDebug() << "Proj3";

    for (int r = 1; r<prj3.n_rows;r++)
    {
        for (int c = 0; c<prj3.n_cols; c++)
        {
            fu.f = prj3(r,c);
            for(int i=0;i<sizeof(float);i++)
            {
                trbuff[indx++] =  fu.fBuff[i];
              //  prjbuff[((r-1)*3 + c)*4 + i] =  fu.fBuff[i];
            //    qDebug() << QString::number(prj3(r,c)) << ":" << QString::number(prjbuff[((r-1)*3 + c)*4 + i]);
            }
        }
    }

    // transfer proj3


    // convert proj4
   // char prjbuff[36];
   // qDebug() << "Proj4";

    for (int r = 1; r<prj4.n_rows;r++)
    {
        for (int c = 0; c<prj4.n_cols; c++)
        {
            fu.f = prj4(r,c);
            for(int i=0;i<sizeof(float);i++)
            {
             trbuff[indx++] =  fu.fBuff[i];
                //   prjbuff[((r-1)*3 + c)*4 + i] =  fu.fBuff[i];
            //    qDebug() << QString::number(prj4(r,c)) << ":" << QString::number(prjbuff[((r-1)*3 + c)*4 + i]);
            }
        }
    }

    // transfer proj2


    // convert Beta
    //char Bbuff[84];
   // qDebug() << "Beta";

    for (int r = 0; r<Bt.n_rows;r++)
    {
        for (int c = 0; c<Bt.n_cols; c++)
        {
            fu.f = Bt(r,c);
            for(int i=0;i<sizeof(float);i++)
            {
              trbuff[indx++] =  fu.fBuff[i];
                //  Bbuff[(r*21 + c)*4 + i] =  fu.fBuff[i];
             //   qDebug() << QString::number(Bt(r,c)) << ":" << QString::number(Bbuff[(r*21 + c)*4 + i]);
            }
        }
    }

    // transfer Beta





    // convert W
    //char Wbuff[1008];
    //qDebug() << "W";

    for (int r = 0; r<W.n_rows;r++)
    {
        for (int c = 0; c<W.n_cols; c++)
        {
            fu.f = W(r,c);
            for(int i=0;i<sizeof(float);i++)
            {
                trbuff[indx++] =  fu.fBuff[i];
               // Wbuff[(r*21 + c)*4 + i] =  fu.fBuff[i];
              //  qDebug() << QString::number(W(r,c)) << ":" << QString::number(Wbuff[(r*21 + c)*4 + i]);
            }
        }
    }

    // transfer Beta

    // debug trbuffer
//    int count = 0;
//        for (int i=0; i<1236/4; i++)
//        {
//            fu.fBuff[0] = trbuff[4*i + 0];
//            fu.fBuff[1] = trbuff[4*i + 1];
//            fu.fBuff[2] = trbuff[4*i + 2];
//            fu.fBuff[3] = trbuff[4*i + 3];

//             qDebug() << QString::number(count++)<< ":" <<QString::number(fu.f);
//        }

     // end debug trbufffer
}


void Train::on_ButtonTransfer_clicked()
{
    sd->setPortdatacmdmodel(2);
    loadBuffer();


    sd->reqModel();     // changing the state machine to model sending and receiving state machine



    char sendbuff[MODEL_PKT_SIZE+1];

    for(int c = 0; c<MODEL_PKT_SIZE; c++)
    {
            sendbuff[c+1] = trbuff[c];
    }
    sendbuff[0] = pktsent;

    sd->writeData(sendbuff, MODEL_PKT_SIZE+1);

}
