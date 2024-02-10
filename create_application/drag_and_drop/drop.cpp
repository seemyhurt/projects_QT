#include "drop.h"
#include "qevent.h"
#include "qmimedata.h"

Drop::Drop(QWidget *pwgt) : QLabel("Drop Area", pwgt)
{
    setAcceptDrops(true);
}

void Drop::dragEnterEvent(QDragEnterEvent* pe)
{
    if (pe->mimeData()->hasFormat("text/uri-list"))
    {
        pe->acceptProposedAction();
    }
}
void Drop:: dropEvent(QDropEvent* pe){
    QList<QUrl> urlList = pe->mimeData()->urls();
    QString str;
    foreach(QUrl url, urlList)
    {
        str += url.toString() + "\n";
    }
    setText("Dropped:\n" + str);
}
