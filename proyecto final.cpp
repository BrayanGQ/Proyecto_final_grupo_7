#include <iostream>
using namespace std;
const char *nombre_archivo = "archivo.dat";
struct Palabra{
	
	char nombre[50];
	char traduccion[50];
	char funcionalidad[200];
};
void leer();
void crear();
void actualizar();
void borrar();
main (){
	leer ();
    crear ();
	borrar();
	actualizar();
	system("pause");
}
void leer(){
	system("cls");
	FILE* archivo=fopen(nombre_archivo,"rb");
	if (!archivo){
	archivo=fopen(nombre_archivo,"w+b");	
	}
	Palabra palabra;
	int id = 0;
	fread(&palabra,sizeof(Palabra),1,archivo);
	
	do{
	cout<<"_________________________________________"<<endl;	
	cout<<"ID"<<"|"<<"PALABRA"<<"|"<<"TRADUCCION"<<endl;	
	cout<<id<<" |"<<palabra.nombre<<"   |"<<palabra.traduccion<<endl;
	cout<<"FUCIONALIDAD"<<endl;
	cout<<palabra.funcionalidad<<endl;
	fread(&palabra,sizeof(Palabra),1,archivo);	
		id+=1;
	}while(feof(archivo)==0);
	fclose(archivo);
	
}
void crear(){
	FILE* archivo=fopen(nombre_archivo,"a+b");
	char res;
	Palabra palabra;
	do{
		fflush(stdin);
		
		cout<<"ingrese una palabra:  ";
		cin.getline(palabra.nombre,50);
		cout<<"ingrese su traduccion:  ";
		cin.getline(palabra.traduccion,50);
		cout<<"defina su funcionalidad:  ";
		cin.getline(palabra.funcionalidad,200);
		
		
		fwrite(&palabra,sizeof(Palabra),1,archivo);
		cout<<"desea ingresar otra palabra (s/n): ";
		cin>>res;
	}while(res=='s'||res=='S');
		
	fclose(archivo);
	leer();
}
    void actualizar(){
    	FILE* archivo=fopen(nombre_archivo,"r+b");
	Palabra palabra;
	int id=0;
	cout<<"ingresa el ID que desea modificar: ";
	cin>>id;
	fseek(archivo,id* sizeof(Palabra),SEEK_SET);
	
		fflush(stdin);
		cout<<"ingrese una palabra:  ";
		cin.getline(palabra.nombre,50);
		cout<<"ingrese su traduccion:  ";
		cin.getline(palabra.traduccion,50);
		cout<<"defina su funcionalidad:  ";
		cin.getline(palabra.funcionalidad,200);
		
		fwrite(&palabra,sizeof(Palabra),1,archivo);
				
	fclose(archivo);
	leer();	
	}
	void borrar(){
		const char *nombre_archivo_temp = "archivo_temp.dat";
		FILE* archivo=fopen(nombre_archivo,"rb");
		FILE* archivo_temp=fopen(nombre_archivo_temp,"w+b");
		
		Palabra palabra;
		int id=0, id_n=0;
		cout<<"ingrese el id que desea eliminar: ";
		cin>>id;
		while(fread(&palabra,sizeof(Palabra),1,archivo)){
		if(id_n!=id){
			fwrite(&palabra,sizeof(Palabra),1,archivo_temp);	
		}
		id_n++;
	}
		fclose(archivo);
		fclose(archivo_temp);
		archivo_temp=fopen(nombre_archivo_temp,"rb");
		archivo=fopen(nombre_archivo,"wb");
		
			while(fread(&palabra,sizeof(Palabra),1,archivo_temp)){
			fwrite(&palabra,sizeof(Palabra),1,archivo);	
		}
			fclose(archivo);
		fclose(archivo_temp);
		
		leer();
	
	}
	
