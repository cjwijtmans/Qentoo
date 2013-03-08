#include "Repository.hpp"

#include <QDir>
#include <QDirIterator>
#include <QFile>
#include <QSet>
#include <QString>
#include <QStringList>
#include <QTextStream>

Repository::Repository(Repositories* repositories)
    :m_Repositories(repositories)
{
}

Repository::Repository(const RepositoryParser& parser, Repositories* repositories)
    :m_Parser(parser)
    ,m_Repositories(repositories)
{
}

Repository::Categories Repository::getCategories() const
{
    Categories categories(m_Parser.getCategories());
    if(m_Repositories)
    {
        Masters strlsMasters = getMasters();
        for(Masters::const_iterator iter = strlsMasters.constBegin(); iter != strlsMasters.constEnd(); ++iter)
        {
            categories.unite(m_Repositories->value(*iter).getCategories());
        }
    }
    return categories;
}

const QDir& Repository::getDir() const
{
    return m_Parser.getDir();
}

Repository::Masters Repository::getMasters() const
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

Repository::Packages Repository::getPackages(const QString& strCategory) const
{
    return m_Parser.getPackages(strCategory);
}
