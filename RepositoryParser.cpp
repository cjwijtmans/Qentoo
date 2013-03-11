#include "RepositoryParser.hpp"

#include <QDebug>
#include <QDir>
#include <QDirIterator>
#include <QFile>
#include <QString>
#include <QTextStream>

RepositoryParser::RepositoryParser()
{
}

RepositoryParser::RepositoryParser(const QDir& dir)
    :m_Dir(dir)
{
}

RepositoryParser::RepositoryParser(const QString& dir)
    :m_Dir(dir)
{
}

RepositoryParser::Categories RepositoryParser::getCategories() const
{
    Categories categories;
    QFile file(m_Dir.filePath("profiles/categories"));
    if(file.open(QFile::ReadOnly))
    {
        QTextStream stream(&file);
        while(!stream.atEnd())
            categories.insert(stream.readLine());
        file.close();
    }
    return categories;
}

const QDir& RepositoryParser::getDir() const
{
    return m_Dir;
}

RepositoryParser::Masters RepositoryParser::getMasters() const
{
    QFile file(m_Dir.filePath("metadata/layout.conf"));
    if(file.open(QFile::ReadOnly))
    {
        QTextStream stream(&file);
        while(!stream.atEnd())
        {
            QString str = stream.readLine();
            if(str.leftRef(str.indexOf('=')).indexOf("masters") > 0)
                return Masters::fromList(str.section('=', 1, 1, QString::SectionSkipEmpty).split(' ', QString::SkipEmptyParts));
        }
        file.close();
    }
    return Masters();
}

QString RepositoryParser::getName() const
{
    QFile file(m_Dir.filePath("profiles/repo_name"));
    file.open(QFile::ReadOnly);
    return QTextStream(&file).readAll();
}

RepositoryParser::Packages RepositoryParser::getPackages() const
{
    //QDirIterator dirIter(m_Dir.filePath(strCategory));
    return Packages::fromList(m_Dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name));
}

RepositoryParser::Packages RepositoryParser::getPackages(const QString& strCategory) const
{
    Packages packages;
    QDirIterator dirIter(m_Dir.filePath(strCategory));
    while(dirIter.hasNext())
    {
        QFile file(QDir(dirIter.filePath()).filePath("*.ebuild"));
        QDebug(QtDebugMsg) << file.fileName();
        if(file.exists())
            packages.insert(dirIter.fileName());
        dirIter.next();
    }
    return packages;
    //return Packages::fromList(QDir(m_Dir.filePath(strCategory)).entryList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name));
}
