#include "Repository.hpp"

#include <QDir>
#include <QFile>
#include <QTextStream>

Repository::Repository(const QDir &dir)
    :m_Dir(dir)
{
}

QStringList Repository::getCategories() const
{
    QStringList strls;
    QFile file(m_Dir.filePath("profiles/categories"));
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        while(!stream.atEnd())
            strls.append(stream.readLine());
        file.close();
    }
    return strls;
}

const QDir& Repository::getDir() const
{
    return m_Dir;
}

QString Repository::getName() const
{
    QFile file(m_Dir.filePath("profiles/repo_name"));
    file.open(QIODevice::ReadOnly);
    return QTextStream(&file).readLine();
}

QStringList Repository::getPackages(const QString& strCategory) const
{
    return QDir(m_Dir.filePath(strCategory)).entryList(QDir::Dirs | QDir::NoDotAndDotDot);
}
