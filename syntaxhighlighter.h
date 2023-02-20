#ifndef SYNTAXHIGHLIGHTER_H
#define SYNTAXHIGHLIGHTER_H

#include <QObject>
#include <QSyntaxHighlighter>
class QTextDocument;
class SyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    explicit SyntaxHighlighter(QTextDocument *parent= nullptr);

private:
    QStringList m_lstKeywords;
protected:
    enum { NormalState = -1, InsideCStyleComment, InsideCString };
    virtual void highlightBlock(const QString&);
    QString getKeyword(int i, const QString& str) const;

};

#endif // SYNTAXHIGHLIGHTER_H
