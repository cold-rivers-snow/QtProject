#ifndef SQL_H
#define SQL_H



class Sql
{
     Q_OBJECT //使用信号与槽需要的宏
public:
    explicit Sql();  //explicit 防止歧义
    bool connectMySQL();
private:

};
#endif // SQL_H
