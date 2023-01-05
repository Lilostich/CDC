#ifndef TESTCASE_H
#define TESTCASE_H

#include <QString>
#include <QJsonObject>
#include <QStringList>
#include <QVariantList>
#include <QVariant>
#include <QJsonValue>
#include <QJsonArray>

#include "file_manager.h"

class TestCase
{
public:
    enum value{
        name,
        description,
        pyScript,
        date_creation,

        value_size
    };

    TestCase();
    TestCase(QString);
    void load(QString);
    void save(QString);

    void set(value tag,QVariant val);
    QVariant get(value tag);
    void create(QString);
    void append(value tag,QVariant);
    void remove(value tag,QVariant);
private:
    QString current_test_name;
    QStringList tags {
        "name",
        "description",
        "pyScript",
        "date_creation"
    };

    QJsonObject obj;
};

class TestSuite
{
public:

    enum value{
        name,
        tests,

        value_size
    };

    TestSuite();
    TestSuite(QString);
    void load(QString);
    void save(QString);

    void set(value tag,QVariant val);
    QVariant get(value tag);
    void create(QString);
    void append(value tag,QVariant);
    void remove(value tag,QVariant);
protected:
    QString current_test_name;
    QStringList tags {
        "name",
        "tests",
    };

    QJsonObject obj;
};

class TestRun// : public TestSuite
{
public:

    enum value{
        name,
        tests,
        lists,

        value_size
    };
    void set(value tag,QVariant val);
    QVariant get(value tag);

    TestRun(QString);
    void load(QString);
    void save(QString);

    QString getProjectName(QString);
private:
    QString current_test_name;
    QStringList tags {
        "name",
        "tests",
        "lists"
    };

    QJsonObject obj;
};

//// NOTE  функции для работы со структурами TestCase, TestSuite, TestRun
//void add_test_to_suite(TestCase& test, TestSuite& suite);
//void add_test_to_run(TestCase& test, TestRun& run);
//void add_suite_to_run(TestSuite& test, TestRun& run);

//void remove_test_from_suite(TestCase& test, TestSuite& suite);
//void remove_test_from_run(TestCase& test, TestRun& run);
//void remove_suite_from_run(TestSuite& test, TestRun& run);

//void clear_suite(TestSuite& suite);
//void clear_run(TestRun& run);

#endif // TESTCASE_H
