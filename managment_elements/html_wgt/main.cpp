#include <QApplication>
#include <QtWidgets/QtWidgets>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel lbl("<H1><CENTER>QLabel - HTML Demo</CENTER></H1>"
               "<H2><CENTER>Image</CENTER><H2>"
               "<CENTER><IMG BORDER=\"0\" img src=\":/proto/map.jpg\"></CENTER>"
               "<H2><CENTER>List</CENTER><H2>"
               "<OL><LI>One</LI>"
               "<LI>Two</LI>"
               "<LI>Three</LI>"
               "</OL>"
               "<H2><CENTER>Font Style</CENTER><H2>"
               "<CENTER><FONT COLOR=RED>"
               "<B>Bold</B>, <I>Italic</I>, <U>Underline</U>"
               "</FONT></CENTER>"
               "<H2><CENTER>Table</CENTER></H2>"
               "<CENTER> <TABLE>"
               "<TR BGCOLOR=#ffOOff>"
               "<TD>1,1</TD><TD>1,2</TD><TD>1,3</TD><TD>1,4</TD>"
               "</TR>"
               "<TR BGCOLOR=YELLOW>"
               "<TD>2,1</TD><TD>2,2</TD><TD>2,3</TD><TD>2,4</TD>"
               "</TR>"
               "<TR BGCOLOR=#OOfOOO>"
               "<TD>3,1</TD><TD>3,2</TD><TD>3,3</TD><TD>3,4</TD>"
               "</TR>"
               "</TABLE> </CENTER>");
    lbl.show();
    return a.exec();
}
