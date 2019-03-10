#ifndef __DATA_TIME_H
#define __DATA_TIME_H

#include <string>
#include <stdio.h>
#include <time.h>
#include "base_typedef.h"
#include "base_namespace.h"

BASE_NAMESPACE_BEGIN_DECL

using namespace std;

class Object
{
public:
    Object(void){};
    virtual bool Equals( const Object *object )   = 0;
    virtual int  CompareTo( const Object *value ) = 0;
    virtual std::string ToString() = 0;

public:
    ~Object(void){ };
};

class DateTime: public Object
{
public:
    DateTime(time_t seconds);
    DateTime(int year, int month, int day);
    DateTime(int year, int month, int day, int hour, int minute, int second);

    //�����ַ�����ʽ ��/��/�� ʱ:��:�� ��:2008/02/03 9:30:20 ������ 01/01/1970 00:00:00;
    DateTime(std::string datetimeStr);
    DateTime(std::string datetimeStr, std::string formaterStr);
public:
    ~DateTime(void);
public:
    //��ָ����������ӵ���ʵ����ֵ��;
    void AddYears(const time_t years);
    //��ָ�����·����ӵ���ʵ����ֵ��;
    void AddMonths(const time_t Months);
    //��ָ���������ӵ���ʵ����ֵ��;
    void AddDays(const time_t days);
    //��ָ����Сʱ���ӵ���ʵ����ֵ��;
    void AddHours(const time_t hours);
    //��ָ���ķ������ӵ���ʵ����ֵ��;
    void AddMinutes(const time_t minutes);
    //��ָ���������ӵ���ʵ����ֵ��;
    void AddSeconds(const time_t seconds);
    //��ָ���������ӵ�Щʵ�ϵ�ֵ��;
    void AddWeeks(const time_t weeks);
    //������ DateTime ��ʵ�����бȽϣ�������һ��ָʾ��һ��ʵ�������ڡ����ڻ������ڵڶ���ʵ����������  ����ֵ��С���� value1 С�� value2�� �� value1 ���� value2�� ������ value1 ���� value2;
    static int Compare(const DateTime *value1, const DateTime *value2);
    //�����ء� ����ʵ����ֵ��ָ���� DateTime ֵ��Ƚϣ���ָʾ��ʵ�������ڡ����ڻ�������ָ���� DateTime ֵ;
    int CompareTo(const Object *value);
    //С���� ��ʵ��С�� value�� �� ��ʵ������ value�� ������ ��ʵ������ value;
    int CompareTo(const DateTime *value);

    //����ָ��������е�����;
    int DaysInMonth(const int year, const int months);
    bool Equals(const Object *object);
    bool Equals(const DateTime *dateTime);
    static bool Equals(const DateTime *value1, const DateTime *value2);
    //�����ַ�����ʽ ��/��/�� ʱ:��:�� ��:02/03/2008 9:30:20 ������ 01/01/1970 00:00:00;
    static DateTime Parse(std::string datetimeStr);
    static DateTime Parse(std::string dateTimeStr, std::string formaterStr);
    //����ǰ DateTime �����ֵת��Ϊ���Ч�Ķ������ַ�����ʾ��ʽ;
    std::string ToShortDateString();
    std::string ToString();
    //formaterStr = "%Y-%m-%d %H:%M:%S" %Y=�� %m=�� %d=�� %H=ʱ %M=�� %S=��;
    std::string ToString(const std::string formaterStr);
public:
    //��ȡ��ʵ������ʾ���ڵ���ݲ���;
    int GetYear();
    //��ȡ��ʵ������ʾ���ڵ���ݲ���;
    int GetMonth();
    // ��ȡ��ʵ������ʾ������Ϊ�����еĵڼ���;
    int GetDay();
    //��ȡ��ʵ������ʾ���ڵ�Сʱ����;
    int GetHour();
    //��ȡ��ʵ������ʾ���ڵķ��Ӳ���;
    int GetMinute();
    //��ȡ��ʵ������ʾ���ڵ��벿��;
    int GetSecond();
    //��ȡ��ʵ������ʾ�����������ڼ�;
    int DayOfWeek();
    //��¼������һ������ĵڼ���,��1��1����,0-365;
    int DayOfYear();

    int64_t	GetSeconds(){return seconds;}
    static DateTime GetNow(); //���ص�ǰ�����Ǽ�;
public:
    bool operator ==(DateTime &dateTime);
    bool operator >(DateTime &dateTime);
    bool operator <(DateTime &DateTime);
    bool operator >=(DateTime &DateTime);
    bool operator <=(DateTime &DateTime);
    bool operator !=(DateTime &DateTime);

private:
    void InitByStr(std::string dateTimeStr, std::string formaterStr);

private:
    time_t seconds; //��1970�������;
    tm date;
};

BASE_NAMESPACE_END_DECL

#endif

