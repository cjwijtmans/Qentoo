#ifndef REPOSITORY_HPP
#define REPOSITORY_HPP

#include <QMap>
#include <QString>
#include <QStringList>

#include "RepositoryParser.hpp"

class Repository
{
public:
    typedef RepositoryParser::Categories Categories;
    typedef RepositoryParser::Masters Masters;
    typedef RepositoryParser::Packages Packages;
    typedef QMap<QString, Repository> Repositories;

    Repository(Repositories* repositories = 0);
    Repository(const RepositoryParser& parser, Repositories* repositories = 0);
    Categories getCategories() const;
    const QDir& getDir() const;
    QString getName() const;
    Masters getMasters() const;
    const RepositoryParser& getParser() const;
    Packages getPackages() const;
    Packages getPackages(const QString& strCategory) const;

private:
    RepositoryParser m_Parser;
    Repositories* m_Repositories;
};

#endif // REPOSITORY_HPP
