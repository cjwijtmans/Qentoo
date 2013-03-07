#include "Repository.hpp"

#include <QDir>
#include <QDirIterator>
#include <QFile>
#include <QSet>
#include <QString>
#include <QStringList>
#include <QTextStream>

Repository::Repository(Portage* portage)
    :m_Portage(portage)
{
}

Repository::Repository(const QDir &dir, Portage* portage)
    :m_Parser(dir)
    ,m_Portage(portage)
{
}

Categories Repository::getCategories() const
{
    Categories categories(m_Parser.getCategories());
    if(m_Portage)
    {
        Masers strlsMasters = getMasters();
        for(Masters::const_iterator iter = strlsMasters.constBegin(); iter != strlsMasters.constEnd(); ++iter)
        {
            categories.unite(m_Portage->getRepository(*iter).getCategories());
        }
    }
    return categories;
}

const QDir& Repository::getDir() const
{
    return m_Parser.getDir();
}

QSet<QString> Repository::getMasters() const
{
    return m_Parser.getMasters();
}

QString Repository::getName() const
{
    return m_Parser.getName();
}

const RepositoryParser& Repository::getParser() const
{
    return m_Parser;
}

QSet<QString> Repository::getPackages(const QString& strCategory) const
{
    return m_Parser.getPackages(strCategory);
}
