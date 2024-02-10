#include "viewer.h"
#include <QApplication>
#include <QtWidgets>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFileSystemWatcher watcher;
    Viewer viewer;

    QStringList args = a.arguments();
    args.removeFirst();
    watcher.addPaths(args);

    viewer.append("Watching files:" + watcher.files().join(";"));
    viewer.append ( "Watching dirs:" + watcher.directories ().join( ";"));
    viewer.show ();

    QObject::connect(&watcher, &QFileSystemWatcher::directoryChanged, &viewer, &Viewer::slotDirectoryChanged);

    QObject::connect(&watcher, &QFileSystemWatcher::fileChanged, &viewer, &Viewer::slotFileChanged);

    return a.exec();
}
