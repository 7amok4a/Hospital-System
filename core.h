//
// Created by matter on 05/12/23.
//

#ifndef HOSPITAL_CORE_H
#define HOSPITAL_CORE_H
std :: string arr[20][5] ;
int Size[20] = {0} ;
void add (int specialization , std :: string name , bool statue) {
    --specialization ;
    if (Size[specialization] <= 4) {
        if (statue == 1) {
            for (int i = Size[specialization] - 1 ; i >= 0 ; --i) {
                arr[specialization][i + 1] = arr[specialization][i] ;
            }
            arr[specialization][0] = name + " urgent"  ;
        }
        else {
            arr[specialization][Size[specialization]] =  (name  + " regular") ;
         }
        ++Size[specialization] ;
    }
    else {
        std :: cout << "Sorry Sir compelete\n" ;
    }
}
void print_all () {
    for (int i = 0 ; i < 20 ; ++i) {
        if (Size[i] == 0) {
            continue;
        }
        else {
            std :: cout << "There are " << Size[i] << " in specialization " << i + 1 << "\n" ;
            for (int ii = 0 ; ii <  Size[i] ; ++ii) {
                std :: cout << arr[i][ii] << "\n" ;
            }
        }
    }
}
#endif //HOSPITAL_CORE_H
