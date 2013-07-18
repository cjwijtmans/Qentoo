#ifndef REPOSITORYPARSER_HPP
#define REPOSITORYPARSER_HPP

#include <QDir>
#include <QSet>
#include <QString>

class RepositoryParser
{
public:
    typedef QSet<QString> Categories;
    typedef QSet<QString> Masters;
    typedef QSet<QString> Packages;
    typedef QMap<QString, QString> Layout;

    RepositoryParser();
    RepositoryParser(const QDir& dir);
    RepositoryParser(const QString& dir);
    Categories getCategories() const;
    const QDir& getDir() const;
    QString getName() const;
    Masters getMasters() const;
    Packages getPackages() const;
    Packages getPackages(const QString& strCategory) const;
    Layout getLayout();

private:
    QDir m_Dir;
};

#endif // REPOSITORYPARSER_HPP
