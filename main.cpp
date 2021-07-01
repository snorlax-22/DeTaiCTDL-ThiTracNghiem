#include"ctdl.h"                
#include"tumlum.h" 
#include"giaodien.h"  
#include"DangNhap.h"             
 
                           
 
using namespace std; 
int main(){          
	resizeConsole(1800, 900);                  
	DANH_SACH_LOP dsl;
     	Doc_file_danh_sach_lop(dsl);
     	Doc_file_dssv(dsl);
 	    DangNhap(dsl);  
 	
	//khungquanlylophoc(0, 0);     
 //UserGV(dsl);                       
	return 0;	            
}                    
