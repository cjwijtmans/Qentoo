#ifndef PORTAGE_HPP
#define PORTAGE_HPP

class Portage;

#include "Categories.hpp"
#include "Repositories.hpp"

#include <QMap>
#include <QString>
#include <QStringList>

class Portage
{
public:
    Portage();
    Categories getCategories() const;
    QString getInfo(const QString& key) const;
    const Repositories& getRepositories() const;
    const Repository& getRepository(const QString& name) const;

private:
    QMap<QString, QString>  m_Info;
    Repositories    m_Repositories;
};

#endif // PORTAGE_HPP
