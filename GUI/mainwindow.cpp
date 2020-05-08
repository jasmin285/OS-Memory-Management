#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // --------------------------------------------- Init GUI Pointers ---------------------------------------------
    mainWidget = new QWidget();
    mainLayout = new QHBoxLayout();
    memoryLayout = new QVBoxLayout();
   v = new QGraphicsView();
    sc= new Sketch();

//    chartView = new QChartView();
//    chart = new QChart();
//    stackedSeries = new QHorizontalStackedBarSeries();

    sWidget = new QStackedWidget();
    pStack = new ProcessStack();
    memLayout = new QVBoxLayout();
    memBox = new QGroupBox("Memory");
    dummyLayout = new QVBoxLayout();
    btns1Layout = new QHBoxLayout();
    processLayout = new QVBoxLayout();
    widget1 = new QWidget();
    widget2 = new QWidget();
    btnAddHole = new QPushButton("Add Hole");
    btnDelHole = new QPushButton("Delete Hole");
    btnNext = new QPushButton("Next");

    btnsLayout= new QHBoxLayout();
    btnAddSeg= new QPushButton("Add Segment");
    btnDelSeg= new QPushButton ("Delete Segment");
    btnNextSeg = new QPushButton("Next Process");
    btnDone = new QPushButton("Previous Process");

//    memory = new QLabel("Memory");
    formLayout = new QFormLayout();
    memLabel = new QLabel("Memory Size:");

    memSizeEdit = new  QLineEdit();

    formLayout->addRow(memLabel,memSizeEdit);



    memTable = new QTableWidget();
    tableHeader = memTable->horizontalHeader();

    memTable->setColumnCount(3);
    QStringList list = {"Hole Name","Base Address","Limit"};
    memTable->setHorizontalHeaderLabels(list);
    tableHeader->setSectionResizeMode(QHeaderView::Stretch);

    processesList = new QListWidget();
    pStackWidget = new QStackedWidget();
//    QVector<Process> processes;
//    QStringList p;
//    processes = Process::all();
//    qDebug()<<processes[0].getName();
//    for (Process i: processes){
//         qDebug()<<i.getName();
//         p.append(i.getName());
//     }



    //---------------------------------------Object Names------------------------------------------
//    memory->setObjectName("MemoryLabel");
    memLabel->setObjectName("MemorySizeLabel");
    memSizeEdit->setObjectName("MemorySizeEdit");
    memTable->setObjectName("MemoryTable");
    //---------------------------------------StyleSheets---------------------------------------
//    memory->setAlignment(Qt::AlignTop);
//    memory->setFixedHeight(47);

//    btnDelHole->setFixedWidth(100);
    memTable->setAlternatingRowColors(true);

    formLayout->setFormAlignment(Qt::AlignCenter); //to be changed
    //----------------------------------------trying chart-----------------------------------------------------------


    Memory= new Shape(1103,64,1258,275,Shape::RECTANGLE,5);
      Memory->setText("Memory" ,Shape::MIDDLE);

        sc->drawShape(Memory);
    //-----------------------------------------Assigning Layouts and Widgets---------------------------------------------------
    this->setCentralWidget(mainWidget);
    mainWidget->setLayout(mainLayout);
    mainLayout->addWidget(sWidget);
    mainLayout->addLayout(memoryLayout);

//    chart->addSeries(stackedSeries);
//    chartView->setChart(chart);
//    memoryLayout->addWidget(chartView);



    sWidget->addWidget(widget1);
    sWidget->addWidget(widget2);
//    sWidget->setCurrentWidget(widget2);

    widget1->setLayout(memLayout);
    memLayout->addWidget(memBox);
//    memLayout->addWidget(memory);
    memBox->setLayout(dummyLayout);
    dummyLayout->addLayout(formLayout);
    dummyLayout->addWidget(memTable);
    memLayout->addLayout(btns1Layout);
    btns1Layout->addWidget(btnAddHole);
    btns1Layout->addWidget(btnDelHole);
    btns1Layout->addWidget(btnNext);

    widget2->setLayout(processLayout);
    /*sWidget->setCurrentIndex() depending on pressing next or back*/
    sWidget->setCurrentIndex(0);
    this->setWindowTitle("Holes Init");
/*in GUICONTROLLER
    pStackWidget->setCurrentIndex(processesList.currentIndex());
*/
    processLayout->addWidget(pStackWidget);
    pStackWidget->addWidget(pStack);
    pStackWidget->setCurrentWidget(pStack);

    processLayout->addLayout(btnsLayout);
    btnsLayout->addWidget(btnAddSeg);
    btnsLayout->addWidget(btnDelSeg);
    btnsLayout->addWidget(btnNextSeg);
    btnsLayout->addWidget(btnDone);
    QGroupBox *processList = new QGroupBox("Processes");
    QGridLayout *lay = new QGridLayout();
    processList->setLayout(lay);
    lay->addWidget(processesList,0,0,1,1);
    processLayout->addWidget(processList);

    QStringList p = {"P1","P2"};
     processesList->addItems(p);

    memoryLayout->addWidget(v);
     v->setScene(sc);

}

MainWindow::~MainWindow()
{
}

