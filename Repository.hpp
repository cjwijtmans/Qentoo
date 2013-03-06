#ifndef REPOSITORY_HPP
#define REPOSITORY_HPP

class Repository;

#include "Categories.hpp"
#include "Packages.hpp"
#include "Portage.hpp"
#include "RepositoryParser.hpp"

#include <QDir>
#include <QString>
#include <QStringList>

class Repository
{
public:
    Repository(Portage* portage = 0);
    Repository(const QDir& dir, Portage* portage = 0);
    Categories getCategories() const;
    const QDir& getDir() const;
    QStringList getExistingCategories() const;
    QString getName() const;
    QStringList getMasters() const;
    const RepositoryParser& getParser() const;
    QStringList getPackages(const QString& strCategory) const;

private:
    RepositoryParser m_Parser;
    Portage* m_Portage;
};

#endif // REPOSITORY_HPP
