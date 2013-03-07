#include "RepositoryParser.hpp"

#include <QDir>
#include <QDirIterator>
#include <QFile>
#include <QString>
#include <QTextStream>

RepositoryParser::RepositoryParserParser()
{
}

RepositoryParser::RepositoryParser(const QDir &dir)
    :m_Dir(dir)
{
}

Categories RepositoryParser::getCategories() const
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

Masters RepositoryParser::getMasters() const
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

Packages RepositoryParser::getPackages(const QString& strCategory) const
{
    //QDirIterator dirIter(m_Dir.filePath(strCategory));
    return Packages::fromList(QDir(m_Dir.filePath(strCategory)).entryList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name));
}
