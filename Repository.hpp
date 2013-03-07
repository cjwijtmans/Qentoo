#ifndef REPOSITORY_HPP
#define REPOSITORY_HPP

class Repository;

#include "Portage.hpp"
#include "RepositoryParser.hpp"

#include <QMap>
#include <QString>
#include <QStringList>

class Repository
{
public:
    typedef RepositoryParser::Categories Categories;
    typedef RepositoryParser::Masters Masters;
    typedef RepositoryParser::Packages Packages;
    typedef QMap<QString, Repository> Repositories;

    Repository(Portage* portage = 0);
    Repository(const RepositoryParser& parser, Portage* portage = 0);
    Categories getCategories() const;
    const QDir& getDir() const;
    QString getName() const;
    Masters getMasters() const;
    const RepositoryParser& getParser() const;
    Packages getPackages(const QString& strCategory) const;

private:
    RepositoryParser m_Parser;
    Portage* m_Portage;
};

#endif // REPOSITORY_HPP
