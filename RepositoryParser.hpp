#ifndef REPOSITORYPARSER_HPP
#define REPOSITORYPARSER_HPP

#include <QDir>
#include <QSet>
#include <QString>

class RepositoryParser
{
public:
    RepositoryParser();
    RepositoryParser(const QDir& dir);
    QSet<QString> getCategories() const;
    const QDir& getDir() const;
    QString getName() const;
    QSet<QString> getMasters() const;
    QSet<QString> getPackages(const QString& strCategory) const;

private:
    QDir m_Dir;
};

#endif // REPOSITORYPARSER_HPP
