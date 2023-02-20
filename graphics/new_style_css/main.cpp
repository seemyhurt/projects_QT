
#include <QtWidgets>
int main (int argc, char** argv){
    QApplication app(argc, argv);
    QWidget wgt;
    QPushButton* pcmdA = new QPushButton ("Button 1");
    QPushButton* pcmdB = new QPushButton ("Button 2");
    QPushButton* pcmdC = new QPushButton ("Button 3");

    QSize size(300,100);
    pcmdA->setMinimumSize(size);
    pcmdB->setMinimumSize(size);
    pcmdC->setMinimumSize(size);

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(pcmdA);
    pvbxLayout->addWidget(pcmdB);
    pvbxLayout->addWidget(pcmdC);
    wgt.setLayout(pvbxLayout);

    QFile file("/home/seemyhurt/Документы/Projects/graph/bottom_new_style_css/buttom.qss");
    file.open(QFile::ReadOnly);
    QString strCSS = QLatin1String(file.readAll() );
    qDebug() << strCSS;
    qApp->setStyleSheet(strCSS);
    wgt . show ( ) ;
    return app.exec();
}
