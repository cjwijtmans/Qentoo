#ifndef PORTAGE_HPP
#define PORTAGE_HPP

class Portage;

#include "Repository.hpp"

#include <QMap>
#include <QSet>
#include <QString>

class Portage
{
public:
    typedef Repository::Categories Categories;
    typedef Repository::Packages Packages;
    typedef QMap<QString, Repository> Repositories;

    Portage();
    Categories getCategories() const;
    QString getInfo(const QString& key) const;
    Packages getPackages(QString strCategory) const;
    const Repositories& getRepositories() const;
    const Repository& getRepository(const QString& name) const;

private:
    QMap<QString, QString>  m_Info;
    Repositories    m_Repositories;
};

#endif // PORTAGE_HPP
