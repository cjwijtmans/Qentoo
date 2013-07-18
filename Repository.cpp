#include "Repository.hpp"

#include <QDebug>
#include <QDir>
#include <QDirIterator>
#include <QFile>
#include <QSet>
#include <QString>
#include <QStringList>
#include <QTextStream>



Repository::Repository()
    :m_Repositories(0)
{
    QDebug(QtDebugMsg) << "Uninitialized Repository object.";
}

Repository::Repository(const Repository& other)
    :m_Parser(other.m_Parser)
    ,m_Repositories(other.m_Repositories)
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
        Masters masters = getMasters();
        for(Masters::const_iterator iter = masters.constBegin(); iter != masters.constEnd(); ++iter)
        {
            if(m_Repositories->contains(*iter))
            {
                categories.unite(m_Repositories->find(*iter)->getCategories());
            }
        }
    }
    categories.intersect(Categories::fromList(getDir().entryList(QDir::Dirs)));
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

Repository::Packages Repository::getPackages() const
{
    return m_Parser.getPackages();
}

Repository::Packages Repository::getPackages(const QString& strCategory) const
{
    return m_Parser.getPackages(strCategory);
}
