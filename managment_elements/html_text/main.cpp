
#include <QtWidgets>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextEdit txt;
    txt.setHtml("<HТМL>"
                "<BODY BGCOLOR=YELLOW>"
                "<CENTER><IMG SRC=\":/proto/map.jpg\"></CENTER>"
                "<FONT COLOR=RED>"
                "<H2><CENTER>Flower`s Poem</CENTER></H2>"
                "<FONT COLOR=BLUE>"
                "<Р ALIGN=\"CENTER\">"
                "<I>"
                "<BR>Flower! Flower!<BR>"
                "Flower! Flower!<BR>"
                "Flower! Flower!<BR>"
                "</!>"
                "</Р>"
                "</FONТ>"
                "</BODY>"
                "</HTML>"
                );
    txt.resize(320,320);
    txt.show();
    return a.exec();
}
