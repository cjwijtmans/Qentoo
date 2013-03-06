#include "Portage.hpp"

#include <QProcess>
#include <QStringList>
#include <QTextStream>

Portage::Portage()
{
    QProcess process;
    process.start("emerge --info", QProcess::ReadOnly);
    process.waitForFinished();
    QTextStream info(process.readAllStandardOutput());
    while(!info.atEnd())
    {
        QString str = info.readLine();
        m_Info.insert(str.section('=', 0, 0, QString::SectionSkipEmpty), str.section('"', 1, 1, QString::SectionSkipEmpty));
    }

    QStringList strlRepositories = m_Info.value("PORTDIR_OVERLAY").split(' ', QString::SkipEmptyParts);
    strlRepositories.append(m_Info.value("PORTDIR"));
    for(QStringList::const_iterator iter = strlRepositories.constBegin(); iter != strlRepositories.constEnd(); ++iter)
    {
        Repository repository(*iter, this);
        m_Repositories.insert(repository.getName(), repository);
    }
}

Categories Portage::getCategories() const
{
    Categories categories;
    for(Repositories::const_iterator iter = m_Repositories.constBegin(); iter != m_Repositories.constEnd(); ++iter)
       categories.unite(iter->getParser().getCategories());
    return categories;
}

QString Portage::getInfo(const QString& key) const
{
    return m_Info.value(key);
}

const Repositories& Portage::getRepositories() const
{
    return m_Repositories;
}

const Repository& Portage::getRepository(const QString& name) const
{
    return *m_Repositories.find(name);
}

