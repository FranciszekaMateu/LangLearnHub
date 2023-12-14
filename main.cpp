#include "./include/ContUsuario.h"
#include "./include/ContCurso.h"
#include "./include/fabricaInterfaz.h"
#include "./include/Utils.h"

#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <set>

int main(void)
{
    system("clear");
    fabricaInterfaz *Fabrica = fabricaInterfaz::getInstancia();
    IContUsuario *Controladorusuario = Fabrica->getIUsuario();
    IContCurso *ControladorCurso = Fabrica->getICurso();
    int opcion = 99;
    bool salirInterno = false;

    // Curso *curso;
    string nick;
    string password;
    string descripcion;
    string nombre;
    string instituto;
    string idiomas;
    string pais;
    int dia, mes, ano;

    idiomas = " ";

    bool salir = false;
    bool encontrado = false;

    while (opcion != 0)
    {
        cout << " =================================================================================" << endl;
        cout << "| [1]  AltaUsuario      [7]  ConsultarCurso     [13] ConsultarEstadisticas        |" << endl;
        cout << "| [2]  ConsultaUsuario  [8]  AgregarLeccion     [14] RealizarEjercicio            |" << endl;
        cout << "| [3]  AltaIdioma       [9]  AgregarEjercicios  [15] Suscribirse a Notificaciones |" << endl;
        cout << "| [4]  ConsultarIdioma  [10] EliminarCurso      [16] Consulta de Notificaciones   |" << endl;
        cout << "| [5]  AltaCurso        [11] HabilitarCurso     [17] Eliminar Suscripciones       |" << endl;
        cout << "| [6]  CargarSistema    [12] Inscribirse        [0]  Salir                        |" << endl; 
        cout << " =================================================================================" << endl;
        cin >> opcion;
        cin.ignore();
        switch (opcion)
        {
        case 1:

            salirInterno = false;
            // AltaUsuario
            while (!salirInterno)
            {
                cout << "AltaProfesor[1] AltaEstudiante [2] Salir[3]" << endl;
                int numero;
                cin >> numero;
                switch (numero)
                {
                case 1:
                {
                    set<string> idiomasdelProfesor;
                    set<string> lista = Controladorusuario->listarNombreIdiomas();
                    if (!lista.empty())
                    {
                        salir = false;

                        cin.ignore();

                        while (!salir)
                        {

                            idiomas = numToString(lista);
                            if (idiomas == "salir")
                            {
                                salir = true;
                            }
                            else
                            {
                                idiomasdelProfesor.insert(idiomas);
                                lista.erase(idiomas);
                            }
                        }

                        system("clear");

                        cout << "ingresa Nickname" << endl;
                        getline(cin, nick);

                        while (Controladorusuario->listarNicknameUsuarios().count(nick) == 1)

                        {
                            cout << "ERROR El nickname ya esta en uso eliga otro" << endl;
                            getline(cin, nick);
                        }

                        cout << "ingresa password" << endl;
                        getline(cin, password);
                        while (password.size() < 6)
                        {
                            cout << "ingresa contraseña de al menos 6 caracteres" << endl;
                            getline(cin, password);
                        }

                        cout << "ingresa descripcion" << endl;
                        getline(cin, descripcion);

                        cout << "ingresa Nombre" << endl;
                        getline(cin, nombre);

                        cout << "ingresa instituto" << endl;
                        getline(cin, instituto);

                        Controladorusuario->seleccionarIdiomas(idiomasdelProfesor);

                        Controladorusuario->altaProfesor(nick, password, nombre, descripcion, instituto);

                        cout << "Profesor creado exitosamente\n"
                             << endl;

                        salirInterno = true;
                    }
                    else
                    {
                        cout << "No hay idiomas en el sistema" << endl;
                        salirInterno = true;
                    }

                    break;
                }

                case 2:
                {
                    cin.ignore();
                    system("clear");

                    cout << "ingresa Nickname" << endl;
                    getline(cin, nick);

                    while (Controladorusuario->listarNicknameUsuarios().count(nick) == 1)
                    {
                        cout << "ERROR El nickname ya esta en uso eliga otro" << endl;
                        getline(cin, nick);
                    }

                    cout << "ingresa password" << endl;
                    getline(cin, password);
                    while (password.size() < 6)
                    {
                        cout << "ingresa contraseña de al menos 6 caracteres" << endl;
                        getline(cin, password);
                    }

                    cout << "ingresa descripcion" << endl;
                    getline(cin, descripcion);

                    cout << "ingresa Nombre" << endl;
                    getline(cin, nombre);

                    string fecha;
                    cout << "Ingrese la fecha en el formato dd/mm/aa: " << endl;
                    getline(cin, fecha);

                    istringstream fechaseparada(fecha);
                    char delim;
                    fechaseparada >> dia >> delim >> mes >> delim >> ano;
                    Controladorusuario->getFecha(dia, mes, ano);
                    cout << "ingresa Pais de residencia" << endl;
                    getline(cin, pais);

                    Controladorusuario->altaEstudiante(nick, password, nombre, descripcion, pais);

                    cout << "Estudiante creado exitosamente" << endl;
                    salirInterno = true;
                    break;
                }

                case 3:
                    salirInterno = true;
                    break;

                default:

                    cout << "Inva " << endl;
                    break;
                }
            }
            break;

        case 2:

            if (!Controladorusuario->listarNicknameUsuarios().empty())
            {

                nombre = numToString(Controladorusuario->listarNicknameUsuarios());
                if (nombre != "salir")
                {
                    system("clear");

                    Controladorusuario->seleccionarUsuario(nombre);

                    if (Controladorusuario->esProfesor())
                    {
                        cout << Controladorusuario->infoProfesor() << endl;
                    }
                    else
                    {
                        cout << Controladorusuario->infoEstudiante() << endl;
                    }
                }
                else
                {
                    salirInterno = true;
                    break;
                }
            }
            salirInterno = true;
            break;
        case 3:

            cout << "Ingrese Idioma" << endl;
            getline(cin, nombre);

            Controladorusuario->altaIdioma(nombre);
            salirInterno = true;
            break;

        case 4:
            for (string i : Controladorusuario->listarNombreIdiomas())
            {
                cout << i << endl;
            }
            salirInterno = true;
            break;
        case 5:
        {
            string nombre, profe, idiomacurso, previa;
            string descripcion;
            set<string> previasCurso;
            int dificultad;
            Dificultad difi;

            cout << "Elige el Profesor del curso" << endl;

            profe = numToString(Controladorusuario->listarProfesores());

            if (profe != "salir")
            {
                ControladorCurso->seleccionarProfesorRecordado(profe);

                cout << "Elige el Nombre del Curso" << endl;
                getline(cin, nombre);
                if (!ControladorCurso->listarNombreCurso().empty())
                {
                    while (ControladorCurso->listarNombreCurso().count(nombre) == 1)
                    {
                        cout << "ERROR El nombre ya esta en uso eliga otro" << endl;
                        getline(cin, nombre);
                    }
                }

                cout << "Ingresa Descripcion" << endl;
                getline(cin, descripcion);

                cout << "Elige la dificltad: Principiante[1], Medio[2], Avanzado[3]" << endl;
                cin >> dificultad;
                cin.ignore();
                switch (dificultad)
                {
                case 1:
                    difi = Principiante;
                    break;

                case 2:
                    difi = Medio;
                    break;
                case 3:
                    difi = Avanzado;
                    break;
                default:
                    difi = Principiante;
                    break;
                };

                cout << "Elige el idioma del curso" << endl;

                idiomacurso = numToString(Controladorusuario->listarNombreIdiomasProfe());
                if (idiomacurso == "salir")
                    break;

                ControladorCurso->seleccionarIdioma(idiomacurso);

                int opcion;
                cout << "El curso tiene previas: Si[1] No[2]" << endl;
                cin >> opcion;
                cin.ignore();
                switch (opcion)
                {
                case 1:
                    previa = " ";
                    if (!ControladorCurso->listarNombreCurso().empty())
                    {
                        while (previa != "salir")
                        {

                            cout << "Elige las previas del curso:" << endl;

                            previa = numToString(ControladorCurso->listarCursosHabilitado());

                            if (previa == "salir")
                                break;

                            {

                                previasCurso.insert(previa);
                            }
                        }
                        ControladorCurso->agregarPreviasCurso(previasCurso);
                    }
                    break;

                case 2:
                    break;
                }

                ControladorCurso->darDeAltaCurso(nombre, descripcion, difi);
                ControladorCurso->seleccionarCurso(nombre);

                cout << "Agregar lecciones [1] Terminar [2]" << endl;
                cin >> opcion;
                cin.ignore();
                switch (opcion)
                {
                case 1:
                {
                    salirInterno = true;
                    while (salirInterno == true)
                    {
                        string Tema, Objetivo;
                        cout << "Tema de la Leccion" << endl;
                        getline(cin, Tema);
                        cout << "Objetivo de la Leccion" << endl;
                        getline(cin, Objetivo);
                        ControladorCurso->crearLeccion(Tema, Objetivo);
                        cout << "Agregar ejercicios [1] Terminar [2]" << endl;
                        cin >> opcion;
                        cin.ignore();
                        switch (opcion)
                        {
                        case 1:
                            salirInterno = true;
                            while (salirInterno == true)
                            {
                                string descripcion;
                                string ejercicio;
                                string solucion;
                                cout << "Tipo de ejercicio: Completar [1] Traduccion [2]" << endl;
                                cin >> opcion;
                                cin.ignore();
                                cout << "Ingrese la descripcion del ejercicio" << endl;
                                getline(cin, descripcion);
                                switch (opcion)
                                {
                                case 1:
                                    cout << "Ingrese la frase a completar" << endl;
                                    getline(cin, ejercicio);
                                    cout << "Ingrese las palabras que faltan separadas por una ," << endl;
                                    getline(cin, solucion);
                                    ControladorCurso->crearCompletar(descripcion, ejercicio, solucion);
                                    cout << "Ejercicio de Completar ingresado al sistema" << endl;
                                    break;

                                case 2:
                                    cout << "Ingrese la frase a traducir" << endl;
                                    getline(cin, ejercicio);
                                    cout << "Ingrese la frase traducida" << endl;
                                    getline(cin, solucion);
                                    ControladorCurso->crearTraduccion(descripcion, ejercicio, solucion);
                                    cout << "Ejercicio de Traduccion ingresado al sistema" << endl;
                                    break;
                                default:
                                    salirInterno = false;
                                    break;
                                }
                                cout << "Continuar agregando ejercicios [1] Terminar [2]" << endl;
                                cin >> opcion;
                                cin.ignore();
                                switch (opcion)
                                {
                                case 1:
                                    break;

                                case 2:
                                    salirInterno = false;
                                    break;
                                default:
                                    salirInterno = false;
                                    break;
                                }
                            }
                            cout << "Leccion ingresada al sistema" << endl;
                            salirInterno = true;
                            break;
                        case 2:
                            break;
                        default:
                            salirInterno = false;
                            break;
                        }
                        cout << "Continuar agregando lecciones [1] Terminar [2]" << endl;
                        cin >> opcion;
                        cin.ignore();
                        switch (opcion)
                        {
                        case 1:
                            break;
                        case 2:
                            salirInterno = false;
                            break;
                        default:
                            salirInterno = false;
                            break;
                        }
                    }
                }
                break;

                case 2:
                    break;
                default:
                    salirInterno = false;
                    break;
                }

                cout << "Curso creado correctamente" << endl;

                salirInterno = true;
                break;
            }
            break;
        }

        case 6:
        {
            // idiomas
            set<string> idiomasProfe;
            Controladorusuario->altaIdioma("Ingles");

            Controladorusuario->altaIdioma("Aleman");

            Controladorusuario->altaIdioma("Portugues");

            idiomasProfe.insert("Aleman");

            idiomasProfe.insert("Portugues");

            // profes
            Controladorusuario->seleccionarIdiomas(idiomasProfe);

            Controladorusuario->altaProfesor("langMaster", "P4s512", "Marta Grecia", "Soy una profesora apasionada por los idiomas.", "Instituto de Idiomas Moderno");

            ControladorCurso->seleccionarIdioma("Ingles");
            idiomasProfe.insert("Ingles");
            Controladorusuario->seleccionarIdiomas(idiomasProfe);

            Controladorusuario->altaProfesor("linguaPro", "Pess23", "Carlos Petro", "Mi objetivo es inspirar a mis estudiantes a explorar nuevas culturas e idiomas", "Centro Global");
            idiomasProfe.clear();
            ControladorCurso->seleccionarIdioma("Aleman");
            idiomasProfe.insert("Aleman");
            Controladorusuario->seleccionarIdiomas(idiomasProfe);

            Controladorusuario->altaProfesor("talkExpert", "Secret1", "Laura Perez", "Soy una profesora entusiasta del aprendizaje de idiomas", "Instituto de Idiomas Vanguardia");

            idiomasProfe.clear();
            ControladorCurso->seleccionarIdioma("Portugues");
            idiomasProfe.insert("Portugues");
            Controladorusuario->seleccionarIdiomas(idiomasProfe);

            Controladorusuario->altaProfesor("lingoSensei", "Secure2", "Franco Lopez", "Apasionada en guiar a mis estudiantes en su viaje por nuevos horizontes idiomaticos", "Centro de Idiomas");
            idiomasProfe.clear();

            idiomasProfe.insert("Ingles");
            Controladorusuario->seleccionarIdiomas(idiomasProfe);
            Controladorusuario->altaProfesor("wordMaestro", "Passw0", "Ana Morales", "Soy una profesora comprometida en desarrollo de habilidades idiomaticas", "Instituto de Idiomas Progreso");

            // Estudiantes

            Controladorusuario->getFecha(15, 7, 1995);
            Controladorusuario->altaEstudiante("jpidiom", "asdfg123", "Juan Perez", "Soy un apasionado del aprendizaje de idiomas.", "Argentina");

            Controladorusuario->getFecha(28, 2, 1998);
            Controladorusuario->altaEstudiante("marsilva", "qwer456", "Maria Silva", "Como amante de los idiomas disfruto explorando nuevas formas de interactuar.", "Ecuador");

            Controladorusuario->getFecha(10, 11, 1994);
            Controladorusuario->altaEstudiante("pero12", "789werty", "Pedro Rodriguez", "Soy un entusiasta del aprendizaje de idiomas.", "Peru");

            Controladorusuario->getFecha(22, 4, 1997);
            Controladorusuario->altaEstudiante("laugu", "c1v2b3m4", "Laura Gutierrez", "Estoy fascinada por la forma en que las palabras pueden unir a las personas", "Chile");

            Controladorusuario->getFecha(3, 9, 1996);
            Controladorusuario->altaEstudiante("carlo22", "tyuipz147", "Carlos Lopez", "Emocionado por adquirir fluidez en diferentes lenguas.", "Uruguay");

            Controladorusuario->getFecha(12, 1, 1999);
            Controladorusuario->altaEstudiante("anator", "1qsxc36", "Ana Torres", "Disfruto de la belleza de las diferentes estructuras y sonidos.", "Argentina");

            Controladorusuario->getFecha(25, 6, 1993);
            Controladorusuario->altaEstudiante("luher24", "t7h8y5u6", "Lucia Hernandez", "Emocionada en la riqueza cultural que cada idioma ofrece.", "Colombia");

            Controladorusuario->getFecha(8, 12, 1997);
            Controladorusuario->altaEstudiante("dagon", "1w2e3r4t5", "David Gonzalez", "Aprender nuevas lenguas y sumergirme en diferentes culturas.", "Uruguay");

            Controladorusuario->getFecha(17, 3, 1995);
            Controladorusuario->altaEstudiante("carmor", "6yu7i8m9", "Carmen Morales", "El aprendizaje de idiomas y expandir mis habilidades comunicativas en diferentes lenguas.", "Chile");

            Controladorusuario->getFecha(2, 8, 1998);
            Controladorusuario->altaEstudiante("jose24", "qwj789p", "Jose Fernandez", "Disfruto del proceso de descubrir nuevas formas de comunicarme", "Bolivia");

            // Cursos

            ControladorCurso->seleccionarProfesorRecordado("langMaster");
            ControladorCurso->seleccionarIdioma("Ingles");
            ControladorCurso->darDeAltaCurso("Ingles para principiantes", "Curso para personas con poco o ningun conocimiento de ingles. Se enfoca en vocabulario basico, gramatica y habilidades de conversacion", Principiante);
            ControladorCurso->seleccionarCurso("Ingles para principiantes");

            // leccion 1
            ControladorCurso->crearLeccion("Saludos y Presentaciones", "Aprender a saludar y despedirse");
            ControladorCurso->crearTraduccion("Presentaciones", "Mucho gusto en conocerte", "Nice to meet you");
            ControladorCurso->crearCompletar("Presentaciones formales", "Please — me to introduce —", "allow, myself");
            ControladorCurso->habilitarCurso();
            // leccion 2
            ControladorCurso->crearLeccion("Articulos y Plurales", "Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los pluralesregulares e irregulares de sustantivos");

            ControladorCurso->crearTraduccion("Plurales regulares", "I have two brothers and three sisters", "Tengo dos hermanos y tres hermanas");
            ControladorCurso->crearCompletar("Sustantivos contables en plural", "Can I have — water, please?", "some");

            ControladorCurso->darDeAltaCurso("Curso de ingles basico", "Construye una base solida en el idioma. Cubre gramatica, vocabulario, comprension auditiva y expresion oral.", Principiante);
            ControladorCurso->seleccionarCurso("Curso de ingles basico");

            ControladorCurso->crearLeccion("Actividades Cotidianas ", "Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los plurales regulares e irregulares de sustantivos");
            ControladorCurso->crearCompletar("Actividades diarias", "Wake —", "up");
            ControladorCurso->crearLeccion("Presente Simple", "Aprender el uso del presente simple");

            ControladorCurso->seleccionarProfesorRecordado("linguaPro");
            set<string> previas;
            previas.insert("Ingles para principiantes");
            ControladorCurso->agregarPreviasCurso(previas);
            ControladorCurso->darDeAltaCurso("Ingles intermedio: mejora tu nivel", "Para estudiantes con conocimientos basicos de ingles que desean avanzar en su habilidad comunicativa. Se centra en lafluidez oral, lectura comprensiva y escritura", Medio);
            ControladorCurso->seleccionarCurso("Ingles intermedio: mejora tu nivel");
            ControladorCurso->crearLeccion("Conversaciones cotidianas", "Aprender a hacer preguntas y respuestas en situaciones comunes");
            ControladorCurso->crearCompletar("Consultas de la hora", "Q: Do you — the time?, A: Yes, it is half — 4", "have,past");
            ControladorCurso->habilitarCurso();

            previas.insert("Ingles intermedio: mejora tu nivel");
            ControladorCurso->agregarPreviasCurso(previas);

            ControladorCurso->darDeAltaCurso("Curso avanzado de ingles", "Dirigido a personas con un nivelintermedio-alto que desean perfeccionarsus habilidades en todos los aspectosdel idioma. Incluye gramatica avanzada, vocabulario y comprension escritay auditiva.", Avanzado);
            ControladorCurso->seleccionarCurso("Curso avanzado de ingles");
            ControladorCurso->habilitarCurso();
            ControladorCurso->crearLeccion("Uso de modales avanzados", "Explorar el uso de los modales complejos");
            ControladorCurso->crearTraduccion("Dar consejos o expresar obligacion", "You should visit that museum", "Deberias visitar ese museo");

            previas.clear();
            ControladorCurso->agregarPreviasCurso(previas);

            ControladorCurso->seleccionarIdioma("Portugues");
            ControladorCurso->darDeAltaCurso("Portugues intermedio", "Curso para aquellos que tienen conocimientos basicos de portugues y deseanmejorar su nivel. Incluye practica delectura, escritura y comprension auditiva.", Medio);
            ControladorCurso->seleccionarCurso("Portugues intermedio");

            ControladorCurso->crearLeccion("Lectura y comprension de textos", "Analizar el contenido, vocabulario y estructuras gramaticales utilizadas");
            ControladorCurso->crearTraduccion("Imperativo", "Fale comigo", "Habla conmigo");
            ControladorCurso->habilitarCurso();

            ControladorCurso->seleccionarProfesorRecordado("lingoSensei");
            previas.insert("Portugues intermedio");

            ControladorCurso->agregarPreviasCurso(previas);
            ControladorCurso->darDeAltaCurso("Portugues avanzado", "Curso avanzado para personas con unnivel intermedio-alto de portugues quedesean perfeccionar su fluidez y dominio del idioma. Se trabaja en la gramatica avanzada y la expresion oral.", Avanzado);

            // Inscripciones
            ControladorCurso->agregarinscr("jpidiom", "Ingles para principiantes", "01/01/2022");
            ControladorCurso->agregarinscr("jpidiom", "Ingles intermedio: mejora tu nivel", "12/06/2022");
            ControladorCurso->agregarinscr("jpidiom", "Curso avanzado de ingles", "02/03/2023");
            ControladorCurso->agregarinscr("marsilva", "Ingles para principiantes", "02/01/2022");
            ControladorCurso->agregarinscr("pero12", "Ingles para principiantes", "02/01/2022");
            ControladorCurso->agregarinscr("laugu", "Ingles para principiantes", "03/01/2023");
            ControladorCurso->agregarinscr("laugu", "Portugues intermedio", "03/01/2023");
            ControladorCurso->agregarinscr("carlo22", "Portugues intermedio", "05/01/2023");

            // ejercicios aprobados
            ControladorCurso->agregarAprobados("jpidiom", "Ingles para principiantes", 1);
            ControladorCurso->agregarAprobados("jpidiom", "Ingles para principiantes", 2);
            ControladorCurso->agregarAprobados("jpidiom", "Ingles para principiantes", 3);
            ControladorCurso->agregarAprobados("jpidiom", "Ingles para principiantes", 4);
            ControladorCurso->agregarAprobados("jpidiom", "Ingles intermedio: mejora tu nivel", 6);
            ControladorCurso->agregarAprobados("marsilva", "Ingles para principiantes", 1);
            ControladorCurso->agregarAprobados("marsilva", "Ingles para principiantes", 2);
            ControladorCurso->agregarAprobados("pero12", "Ingles para principiantes", 1);
            ControladorCurso->agregarAprobados("pero12", "Ingles para principiantes", 2);
            ControladorCurso->agregarAprobados("pero12", "Ingles para principiantes", 4);
            system("clear");
            cout
                << "Sistema Cargado con exito" << endl;
            break;
        }

        case 7:
        {

            string res = numToString(ControladorCurso->listarNombreCurso());

            if (res != "salir")
            {
                ControladorCurso->seleccionarCurso(res);
                cout << ControladorCurso->infoCurso(res);
                vector<InfoLeccion *> infol = ControladorCurso->listarInfoLeccion();
                int x = 1;
                for (InfoLeccion *i : infol)
                {
                    cout << "" << endl;
                    cout << "Leccion nº" << x << endl;
                    x++;
                    cout << i;
                    ControladorCurso->seleccionarLeccion(i->getTema());
                    if (!ControladorCurso->listarEjercicios().empty())
                    {

                        for (pair<int, string> e : ControladorCurso->listarEjercicios())
                        {
                            cout << "" << endl;

                            ControladorCurso->seleccionarEjercicio(e.first);
                            if (ControladorCurso->mostrarParticular(ControladorCurso->mostrarEjercicio()))
                                cout << ControladorCurso->mostrarParticularC(ControladorCurso->mostrarEjercicio());
                            else
                                cout << ControladorCurso->mostrarParticularT(ControladorCurso->mostrarEjercicio());
                        };
                    }
                    delete i;
                }
                if (!ControladorCurso->getInfoInscripciones().empty())
                {
                    cout << "Inscripciones :" << endl;
                    for (Infoinscripcion * i : ControladorCurso->getInfoInscripciones())
                    {
                        cout << i << endl;
                        delete i;
                    }
                }
            }
            break;
        }

            case 8: // Agregar Lecciones
        {
            cout << "Seleccione un curso no habilitado" << endl;
            if (ControladorCurso->listarNombreCursosNoHabilitados().size() > 0)
            {
                string res = numToString(ControladorCurso->listarNombreCursosNoHabilitados());
                if (res != "salir")
                {
                    ControladorCurso->seleccionarCurso(res);
                    cout << "Ingrese el tema de la leccion" << endl;
                    string tema, objetivo;
                    getline(cin, tema);
                    cout << "Ingrese el objetivo de la leccion" << endl;
                    getline(cin, objetivo);

                    ControladorCurso->crearLeccion(tema, objetivo);
                    string input;
                    int choice = 0;

                    do
                    {
                        cout << "[1] Agregar Ejercicios [0] Salir" << endl;
                        getline(cin, input);
                        stringstream stream(input);
                        if (stream >> choice) {
                            if (choice == 1)
                            {
                                cout << "[1] Ejercicio Traduccion [2] Ejercicio Completar" << endl;
                                getline(cin, input);
                                stringstream stream(input);
                                if (stream >> choice) {
                                    cout << "Ingrese la descripcion del ejercicio" << endl;
                                    string descrp;
                                    getline(cin, descrp);
                                    string ejercicio;
                                    string solucion;
                                    switch (choice)
                                    {
                                    case 1:
                                        cout << "Ingrese la frase a traducir" << endl;
                                        getline(cin, ejercicio);
                                        cout << "Ingrese la frase traducida" << endl;
                                        getline(cin, solucion);
                                        ControladorCurso->crearTraduccion(descrp, ejercicio, solucion);
                                        cout << "Ejercicio de Traduccion ingresado al sistema" << endl;
                                        break;
                                    case 2:
                                        cout << "Ingrese la frase a completar" << endl;
                                        getline(cin, ejercicio);
                                        cout << "Ingrese las palabras que faltan separadas por una ," << endl;
                                        getline(cin, solucion);
                                        ControladorCurso->crearCompletar(descrp, ejercicio, solucion);
                                        cout << "Ejercicio de Completar ingresado al sistema" << endl;
                                        break;
                                    default:
                                        break;
                                    }
                                } else {
                                    cout << "Error, ingreso un string" << endl;
                                }
                            }
                        } else {
                            cout << "Error, ingreso un string" << endl;
                        }
                    } while (choice != 0);
                }
            }
            else
                cout << "Error, no se encontraron cursos no habilitados en el sistema" << endl;
        }
        break; // Case 8

        case 9: // Agregar Ejercicios
        {

            if (ControladorCurso->listarNombreCursosNoHabilitados().size() > 0)
            {
                cout << "Seleccione un curso no habilitado" << endl;
                string cursoS = numToString(ControladorCurso->listarNombreCursosNoHabilitados());
                if (cursoS == "salir")
                    break;
                ControladorCurso->seleccionarCurso(cursoS);

                cout << "Seleccione una leccion" << endl;
                if (ControladorCurso->listarLecciones().size() > 0)
                {
                    string LeccionS = numToString(ControladorCurso->listarLecciones());
                    if (LeccionS == "salir")
                        break;
                    ControladorCurso->seleccionarLeccion(LeccionS);

                    int choice = 1;

                    do
                    {
                        if (choice == 1)
                        {
                            cout << "[1] Ejercicio Traduccion [2] Ejercicio Completar" << endl;
                            cin >> choice;
                            cin.ignore();
                            cout << "Ingrese la descripcion del ejercicio" << endl;
                            string descrp;
                            getline(cin, descrp);
                            string ejercicio;
                            string solucion;
                            switch (choice)
                            {
                            case 1:
                                cout << "Ingrese la frase a traducir" << endl;
                                getline(cin, ejercicio);
                                cout << "Ingrese la frase traducida" << endl;
                                getline(cin, solucion);
                                ControladorCurso->crearTraduccion(descrp, ejercicio, solucion);
                                cout << "Ejercicio de Traduccion ingresado al sistema" << endl;
                                break;
                            case 2:
                                cout << "Ingrese la frase a completar" << endl;
                                getline(cin, ejercicio);
                                cout << "Ingrese las palabras que faltan separadas por una ," << endl;
                                getline(cin, solucion);
                                ControladorCurso->crearCompletar(descrp, ejercicio, solucion);
                                cout << "Ejercicio de Completar ingresado al sistema" << endl;
                                break;
                            default:
                                break;
                            }
                        }
                        cout << "[1] Agregar mas Ejercicios [0] Salir" << endl;
                        cin >> choice;
                        cin.ignore();
                    } while (choice != 0);
                }
                else
                    cout << "Error, el curso no tiene lecciones" << endl;
            }
            else
                cout << "Error, no se encontraron cursos no habilitados en el sistema" << endl;
        }
        break;
        case 10:
        {
            string aux;
            cout << "Seleccionar Curso" << endl;
            aux = numToString(ControladorCurso->listarNombreCurso());
            if (aux == "salir")
                break;
            ControladorCurso->eliminarCurso(aux);
            cout << "Curso eliminado" << endl;
            break;
        }

        case 11:
        {

            string nombre = numToString(ControladorCurso->listarNombreCursosNoHabilitados());
            if (nombre != "salir")
            {
                ControladorCurso->seleccionarCurso(nombre);
                ControladorCurso->habilitarCurso();
            }
            break;
        }

        case 12:
        {
            string nick;
            string curso;
            int choice;
            system("clear");
            /*  cout << "Ingresar nickname del estudiante a inscribir" << endl;
             getline(cin, nick); */
            nick = numToString(Controladorusuario->listarEstudiantes());
            if (nick == "salir")
                break;
            system("clear");
            set<InfoCursoDisponible *> lista = ControladorCurso->listarCursosDisponibles(nick);
            if (lista.empty())
            {
                cout << "No hay cursos disponibles" << endl;
                break;
            }
            set<InfoCursoDisponible *>::iterator it = lista.begin();
            int contador = 1;
            while (it != lista.end())
            {
                cout << "------- | [" << contador << "] | -------" << endl;
                cout << *it;
                cout << "-----------------------" << endl << endl << endl;
                it++;
                contador++;
            }
            do {
                cout << "Digite el numero del curso" << endl;
                cin >> choice;
                if (choice > contador - 1 || choice == 0) 
                    cout << "Error, seleccione un numero de la lista" << endl;
            } while ((choice > contador - 1 ) || (choice == 0));
            choice--;
            it = lista.begin();
            while (it != lista.end() && choice > 0)
            {
                it++;
                choice--;
            }
            curso = (*it)->getNombre();
            ControladorCurso->inscribirseCurso(curso);
            system("clear");
            cout << "Inscripcion a " << curso << " realizada con exito" << endl;
            for (InfoCursoDisponible * i : lista) delete i;

            break;
        }
        case 13:
        {
            system("clear");
            int opcion;
            cout << "Obtener estadisitcas de: [1]Estudiantes, [2]Profesores, [3]Cursos" << endl;
            cin >> opcion;
            cin.ignore();
            switch (opcion)
            {
            case 1:
            {
                string e = numToString(Controladorusuario->listarEstudiantes());
                system("clear");
                if (e == "salir")
                    break;
                set<ProgresoCurso *> prog = Controladorusuario->listarProgresoCursosEstudiante(e);
                if (prog.empty())
                    cout << "No hay inscripciones para este estudiamte" << endl;
                else
                {
                    for (ProgresoCurso *i : prog) {
                        cout << i << endl;
                        delete i;
                    }
                }
                prog.clear();
                break;
            }
            case 2:
            {
                string p = numToString(Controladorusuario->listarProfesores());
                system("clear");
                if (p == "salir")
                    break;
                set<PromedioCurso *> prom = Controladorusuario->listarPromedioCursosProfesor(p);
                if (prom.empty())
                    cout << "No hay cursos de este profesor" << endl;
                else
                {
                    for (PromedioCurso *i : prom) {
                        cout << i << endl;
                        delete i;
                    }
                }
                prom.clear();
                break;
            }
            case 3:
            {
                string c = numToString(ControladorCurso->listarCursos());
                if (c == "salir")
                    break;
                system("clear");
                EstCurso *est = ControladorCurso->estCurso(c);
                cout << est << endl;
                break;
            }
            default:
                break;
            }
            break;
        }
        case 14:
        {
            system("clear");
            cout << "Seleccione un estudiante del sistema" << endl;
            string est = numToString(Controladorusuario->listarEstudiantes());
            if (est != "salir") {
                Controladorusuario->seleccionarUsuario(est);
                if (Controladorusuario->listarCursosEstudianteNoAprobados(est).empty()) {
                    if (Controladorusuario->tieneInscripciones()) {
                        cout << "El estudiante no esta inscrito a ningun curso" << endl;
                    } else {
                        cout << "Todos los cursos se encuentran aprobados" << endl;
                    }
                    break;
                }
                cout << "Seleccione un curso " << endl;
                string estChoice = numToString(Controladorusuario->listarCursosEstudianteNoAprobados(est));
                if (estChoice != "salir") {
                    set<DTEjercicio *> ejercicios = Controladorusuario->listarEjerciciosNoAprobados(estChoice);
                    if (ejercicios.empty())
                    {
                        cout << "No hay ejercicios para este curso" << endl;
                        break;
                    }
                    else
                    {
                        cout << "Seleccione un ejercicio por su respectiva id " << endl;
                        for (DTEjercicio *i : ejercicios)
                        {
                            cout << "[" << i->getId() << "] " << i->getDescripcion() << endl;
                            delete i;
                        }
                        int choice;
                        cin >> choice;
                        cin.ignore();
                        Controladorusuario->seleccionarEjercicio(choice);
                        string tipoEjercicio = Controladorusuario->tipoEjRecord();
                        string particular = Controladorusuario->mostrarParticular2();
                        system("clear");
                        cout << "- Ejercicio de " << tipoEjercicio << " -" << endl;
                        if (tipoEjercicio == "Completar")
                        { // Completar
                            cout << "La palabra a completar es: " << particular << endl;
                        }
                        else
                        { // Creado asi para mayor facilidad a la hora de agregar mas tipos de ejercicios
                            cout << "La frase a Traducir es: " << particular << endl;
                        }
                        cout << "Ingrese la solucion del ejercicio" << endl;
                        string res;
                        getline(cin, res);
                        bool esCorrecto = Controladorusuario->ingresarSol(res);
                        if (esCorrecto) {
                            cout << "La solucion ingresada es correcta" << endl;
                        } else {
                            cout << "La solucion ingresada es incorrecta" << endl;
                        }
                    } 
                }
            } 
            break;
        }

        case 15:
        {
            system("clear");
            string nick = numToString(Controladorusuario->listarNicknameUsuarios());
            if (nick == "salir")
                break;
            system("clear");
            Controladorusuario->seleccionarUsuario(nick);
            cout << "Nickname ingresado." << endl;
            salirInterno = true;
            set<string> res;
            set<string> idiomas = Controladorusuario->listarNombreIdiomasNoSuscritos();
            while (salirInterno == true) {
                cout << "Idiomas disponibles: " << endl;
                if (idiomas.empty()){
                    cout << "Ya se ha suscripto a todos los idiomas" << endl;
                    salirInterno = false;
                }
                else{
                    string idiom = numToString(idiomas);
                    if (idiom == "salir")
                        break;
                    system("clear");
                    idiomas.erase(idiom);
                    res.insert(idiom);
                    cout << "Idioma ingresado." << endl;
                    cout << "Suscribirse a otro idioma [1]Si [2]No" << endl;
                    int num;
                    cin >> num;
                    cin.ignore();
                    switch (num)
                    {
                    case 1:
                        break;
                    case 2:
                        salirInterno = false;
                        break;
                    default:
                        salirInterno = false;
                        break;
                    }
                }
            }
            system("clear");
            if (!res.empty()){
                Controladorusuario->seleccionarIdiomasASuscribirse(res);
                for (string i : res){ 
                    cout << "Suscripcion a " << i << " realizada con exito" << endl; 
                }
                
            }    
            break;
        }

        case 16://no selecciona usuario o cuando te suscribis al idioma lo hace mal(muy probable)
        {
            system("clear");
            string nick = numToString(Controladorusuario->listarNicknameUsuarios());
            if (nick != "salir" ) {
                Controladorusuario->seleccionarUsuario(nick);
                if (Controladorusuario->listarNotificacionesUsuario().empty())
                    cout << "No hay notificaciones nuevas." << endl;
                    else {
                        cout << "Notificaciones: " << endl;
                        for (DTNotificacion* i : Controladorusuario->listarNotificacionesUsuario()) {
                            cout << i << endl;
                            delete i;
                        }
                    }
                Controladorusuario->eliminarNotificacionesUsuario();
            }
            break;
        }

        case 17:
        {
            system("clear");
            string nick = numToString(Controladorusuario->listarNicknameUsuarios());
            if (nick != "salir" ) {
                Controladorusuario->seleccionarUsuario(nick);
                bool control = true;
                while (control) {
                    if (Controladorusuario->listarIdiomasSuscritos().empty()) {
                        control = false;
                        cout << "No hay Idiomas suscritos." << endl;
                    } else {
                        cout << "Seleccione un Idioma." << endl;
                        set<string> res;
                        string idioma = numToString(Controladorusuario->listarIdiomasSuscritos());
                        if (idioma != "salir") {
                            res.insert(idioma);
                            Controladorusuario->eliminarSuscripcion(res);
                            cout << "Seleccionar otro Idioma[1] Salir[2]" << endl;
                            int aux;
                            cin >> aux;
                            cin.ignore();
                            if (aux == 2) {
                                control = false;
                            }  
                        } else {
                            control = false;
                        }
                    }
                }
            }
            break;
        }
        default:
        //return 0; comentado porque no andaba en caso
            break;
        }
    }

    // Limpieza de memoria 

    ControladorCurso->limpiarCursos();
    Controladorusuario->limpiarIdiomas();
    Controladorusuario->limpiarUsuarios();
    
    delete ControladorCurso;
    delete Controladorusuario;
    delete Fabrica;
    return 0;
}

