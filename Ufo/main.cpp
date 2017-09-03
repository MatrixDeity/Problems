//////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <sstream>
#include <string>
#include <locale>
//////////////////////////////////////////////////////////////////////////////////////////////
typedef std::string     T_str;
//////////////////////////////////////////////////////////////////////////////////////////////
bool  successfully_get_val_from_str_with_base
    (
        const T_str&    s,
        int             base,
        int&            val
    )
{
    char    *end    =   0;
    val             =   strtol
                            ( 
                                s.c_str(), 
                                &end, 
                                base 
                            );
 
    return      !s.empty()
            &&  *end    ==  0;
}
//////////////////////////////////////////////////////////////////////////////////////////////
int  get_min_base
    ( 
        const T_str&    L,
        const T_str&    R,
        const T_str&    SUM
    )
{
    const int   EMPTY_BASE  =   -1;
    const int   BASE_MIN    =   2;
    const int   BASE_MAX    =   36;
 
    int     val_L       =   0;
    int     val_R       =   0;
    int     val_SUM     =   0;
 
    for(int  base = BASE_MIN; base <= BASE_MAX; ++base)
    {
        if  (
                    successfully_get_val_from_str_with_base ( L,    base,   val_L       )
                &&  successfully_get_val_from_str_with_base ( R,    base,   val_R       )
                &&  successfully_get_val_from_str_with_base ( SUM,  base,   val_SUM     )
 
                &&  val_L + val_R == val_SUM
            )
        {
            return  base;
        }
    }
    return  EMPTY_BASE;
}
//////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    setlocale(0,"");
 
    for(;;)
    {
        T_str   A;
        T_str   B;
        T_str   C;
 
        char    c   =   0;
        
        bool    str_is_correct    =   false;
 
        do
        {
            T_str   s;
 
            getline
                (
                    std::cin,
                    s
                );
 
            std::istringstream  ssin(s);
 
            ssin    >>  A;
            ssin    >>  B;
            ssin    >>  C;
            str_is_correct    =         !A.empty()
                                    &&  !B.empty()
                                    &&  !C.empty()
                                    &&  (ssin    >>  c)     ==  0;
        }while  ( !str_is_correct );
 
        std::cout   <<  get_min_base( A, B, C )
                    <<  std::endl
                    <<  std::endl;
    }
}

