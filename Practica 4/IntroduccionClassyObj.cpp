#include <iostream>
#include <vector>
using namespace std;

int num_users;
int cuenta;

string randomString(int len)
{
    // A function to generate random strings of length --> 
    // "len" 
    string str;
    for (int i = 0; i < len; i++) {
        char ch = 'A' + rand() % 26;
        str.push_back(ch);
    }
}

int aleatorioGen() 
{
    srand(time(0));
    return rand() % 3;
}

class materiales
{
public:

    static void altaMaterial(materiales arr[])
    {
        srand(time(0));
        int autortemp = 0;
        int directortemp = 0;
        string gen[3] = { "anime", "accion", "kids" };
        string tipo[3] = { "movie", "libro", "music" };
        
        for (int i = 0; i <= 9; i++) 
        {
            arr[i].id = randomString(10);
            arr[i].titulo = randomString(50);
            arr[i].genero = gen[aleatorioGen()];
            arr[i].tipo = tipo[aleatorioGen()];
            arr[i].duracion = rand() % 205;
            arr[i].region = rand() % 9;
            cout << "cuantos autores ? ";
            cin >> autortemp;
            for (int j = 0; j <= autortemp - 1; j++) 
            {
                cout << "Dame el autor " << i << "?  : ";
                cin >> arr[i].actor[j];
                cout << endl;
            }
            cout << "cuantos directores ? ";
            cin >> directortemp;
            for (int j = 0; j <= autortemp - 1; j++)
            {
                cout << "Dame el director " << i << "?  : ";
                cin >> arr[i].actor[j];
                cout << endl;
            }
            arr[i].inventario = rand() % 10;
            arr[i].referencia = rand() % 2;

            
        }
    }

    static void imprimeMaterial(vector <materiales> vm)
    {
        cout << "Prueba" << endl;
        for (int i = 0; i <= vm.size() - 1; i++)
        {
            cout << vm[i].id << endl;
            cout << vm[i].titulo << endl;

        }
    }

private:
    string id;
    string titulo;
    string genero;
    string tipo;
    double duracion;
    int region;
    vector<string> actor;
    vector<string> director;
    int inventario;
    bool referencia;
};

class usuario 
{
public:
    usuario() 
    {
        this->matricula = 0;
        this->nombre = "";
        this->ap = "";
        this->dom.calle = "";
        this->dom.numero_externo = "";
        this->dom.numero_interno = "";
        this->dom.colonia = "";
        this->dom.municipio = "";
        this->dom.estado = "";
        this->dom.pais = "";
        

    }
    static void altaAlumno(usuario &temp, vector<usuario> &vu)
    {
        
        cout << "Dame la matricula : ";
        cin >> temp.matricula;
        cout << endl;
        cout << "Dame la nombre : ";
        cin >> temp.nombre;
        cout << endl;
        cout << "Dame la ap : ";
        cin >> temp.ap;
        cout << endl;
        cout << "Dame la calle : ";
        cin >> temp.dom.calle;
        cout << endl;
        cout << "Dame la numero externo : ";
        cin >> temp.dom.numero_externo;
        cout << endl;
        cout << "Dame la numero interno : ";
        cin >> temp.dom.numero_interno;
        cout << endl;
        cout << "Dame la colonia : ";
        cin >> temp.dom.colonia;
        cout << endl;
        cout << "Dame la municipio : ";
        cin >> temp.dom.municipio;
        cout << endl;
        cout << "Dame la estado : ";
        cin >> temp.dom.estado;
        cout << endl;
        cout << "Dame la pais : ";
        cin >> temp.dom.pais;
        cout << endl;
        cout << "Dame telefono : ";
        cin >> temp.telefono;
        cout << endl;
        cout << "Dame dias : ";
        cin >> temp.dias;
        cout << endl;
        cout << "Dame la vencido : ";
        cin >> temp.vencido;
        cout << endl;
        vu.push_back(temp);
    }

    static void imprimeDatos(vector <usuario> v1) 
    {
        cout << "Prueba" << endl;
        for (int i = 0; i <= v1.size() - 1; i++) 
        {
            cout << v1[i].matricula << endl;
            cout << v1[i].dom.calle << endl;
        }
    }

    static void buscar(vector <usuario> vt) 
    {
        cout << "Dame la matricula ";
        cin >> cuenta;
        for (auto i = 0; i <= vt.size() - 1; i++)
        {
            if (vt[i].matricula == cuenta)
            {
                cout << "encontrado " << endl;
                vt.erase(vt.begin() + i);
            }
            
        }
        
    }

private:
    int matricula;
    string nombre;
    string ap;
    struct domicilo 
    {
        string calle;
        string numero_externo;
        string numero_interno;
        string colonia;
        string municipio;
        string estado;
        string pais;
    } dom;
    string telefono;
    int dias;
    bool vencido;

    
};
int main()
{

    materiales mat[10];
    
    vector <usuario> v1;
    vector <usuario*> v2;
    usuario* s1 = new usuario();
    materiales temp2;
    materiales::altaMaterial(mat);
   //cout << "Tamaño máximo "<< v1.max_size() << endl;
    cout << "dame el numero de usuarios a dar de alta : ";
    cin >> num_users;
    cout << endl;
    while (num_users > 0) 
    {
        usuario temp;
        usuario::altaAlumno(temp,v1);
        
        num_users--;
    }
    
    usuario::imprimeDatos(v1);
    // find a member
    usuario::buscar(v1);

    
}