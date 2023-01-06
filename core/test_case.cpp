#include "test_case.h"

TestCase::TestCase(QString name)
{
    obj = file_manager::read_test(name);
    current_test_name = name;
}

void TestCase::load(QString name)
{
     obj = file_manager::read_test(name);
     current_test_name = name;
}

void TestCase::save(QString name = "")
{
    if (name == ""){
        file_manager::write_test(current_test_name,obj);
    } else {
        file_manager::write_test(name,obj);
    }

}

void TestCase::set(value tag, QVariant val)
{
    switch (val.type()) {
    case QVariant::Type::String:
        obj[tags[tag]] = val.toJsonValue();
        break;
    case QVariant::Type::StringList:
//        obj[tags[tag]] = QJsonArray::fromStringList(val.toStringList());
        obj[tags[tag]] = val.toJsonArray();
        break;
    default:
        qDebug("For this type of QVariant haven't impl");
        break;
    }
}

QVariant TestCase::get(value tag)
{
    if (obj.find(tags[tag]) != obj.end())
        return obj[tags[tag]].toVariant();
    else{
        qDebug("no tag");
        return QVariant();
    }
}

void TestCase::append(value tag,QVariant val)
{
    QJsonArray array = obj[tags[tag]].toArray();
    array.push_back(val.toJsonValue());
}

void TestCase::remove(value tag, QVariant val)
{
    if (obj.find(tags[tag]) != obj.end()){
        if (obj[tags[tag]].toArray().contains(val.toJsonValue())){
            for (int i = 0; i < obj[tags[tag]].toArray().size(); i++){
                obj[tags[tag]].toArray().removeAt(i);
            }
        } else
            qDebug("no value in tag");
    } else
        qDebug("no tag");
}

TestSuite::TestSuite(QString name)
{
    obj = file_manager::read_list(name);
    current_test_name = name;
}

void TestSuite::load(QString name)
{
    obj = file_manager::read_list(name);
    current_test_name = name;
}

void TestSuite::save(QString name)
{
    if (name == ""){
        file_manager::write_list(current_test_name,obj);
    } else {
        file_manager::write_list(name,obj);
    }
}

void TestSuite::set(value tag, QVariant val)
{
    switch (val.type()) {
    case QVariant::Type::String:
        obj[tags[tag]] = val.toJsonValue();
        break;
    case QVariant::Type::StringList:
//        obj[tags[tag]] = QJsonArray::fromStringList(val.toStringList());
        obj[tags[tag]] = val.toJsonArray();
        break;
    default:
        qDebug("For this type of QVariant haven't impl");
        break;
    }
}

QVariant TestSuite::get(value tag)
{
    if (obj.find(tags[tag]) != obj.end())
        return obj[tags[tag]].toVariant();
    else{
        qDebug("no tag");
        return QVariant();
    }
}

void TestSuite::create(QString)
{

}

void TestSuite::append(value tag, QVariant val)
{
    QJsonArray array = obj[tags[tag]].toArray();
    array.push_back(val.toJsonValue());
}

void TestSuite::remove(value tag, QVariant val)
{
    if (obj.find(tags[tag]) != obj.end()){
        if (obj[tags[tag]].toArray().contains(val.toJsonValue())){
            for (int i = 0; i < obj[tags[tag]].toArray().size(); i++){
                obj[tags[tag]].toArray().removeAt(i);
            }
        } else
            qDebug("no value in tag");
    } else
        qDebug("no tag");
}

void TestRun::set(value tag, QVariant val)
{
    switch (val.type()) {
    case QVariant::Type::String:
        obj[tags[tag]] = val.toJsonValue();
        break;
    case QVariant::Type::StringList:
//        obj[tags[tag]] = QJsonArray::fromStringList(val.toStringList());
        obj[tags[tag]] = val.toJsonArray();
        break;
    default:
        qDebug("For this type of QVariant haven't impl");
        break;
    }
}

QVariant TestRun::get(value tag)
{
    if (obj.find(tags[tag]) != obj.end())
        return obj[tags[tag]].toVariant();
    else{
        qDebug("no tag");
        return QVariant();
    }
}

TestRun::TestRun(QString name)
{
    obj = file_manager::read_run(name);
    current_test_name = name;
}

void TestRun::load(QString name)
{
    obj = file_manager::read_run(name);
    current_test_name = name;
}

void TestRun::save(QString name)
{
    if (name == ""){
        file_manager::write_run(current_test_name,obj);
    } else {
        file_manager::write_run(name,obj);
    }
}

QString TestRun::getProjectName(QString name = "")
{
    return file_manager::get_project_of_run(name);
}
