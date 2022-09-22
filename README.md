# SDG1
La explicación de todos los códigos está en los vídeos de la lista de reproducción de la asignatura. Puedes acceder pinchando en la imagen:
[![Conceptos básicos de C](https://github.com/josueportiz/c_basics/blob/assets/images/video_list.jpg?raw=true)](https://youtube.com/playlist?list=PLTFFovUxjNnn19myGVw1kwh6GPbRxwIcC "Conceptos básicos de C")

Esta es la estructura de los proyectos de SDG1 para **compilación nativa** usando VSCode.
La diferencia fundamental con la estructura de los proyectos para SDG2 es que **no contiene** las carpetas `drivers` y `port`.

```
📂sdg
┣ 📂projects
┃ ┣ 📦projects.code-workspace
┃ ┣ 📂project_name
┃ ┃ ┣ 📂.vscode    
┃ ┃ ┃ ┣ 📜launch.json
┃ ┃ ┃ ┗ 📜tasks.json
┃ ┃ ┣ 📂include
┃ ┃ ┣ 📂lib
┃ ┃ ┣ 📂output
┃ ┃ ┣ 📂src
┃ ┃ ...
┃ ┃ ┗ 📜Makefile
┃ ┣ 📂another_project_name
┃ ┃ ┣ 📂.vscode    
┃ ┃ ┣ 📂include
┃ ┃ ┣ 📂lib
┃ ┃ ┣ 📂output
┃ ┃ ┣ 📂src
┃ ┃ ...
┃ ┃ ┗ 📜Makefile
┃ ┗ ...
┗
```

- Hay que buscar un lugar donde dejar la carpeta `sdg`.
- La carpeta `sdg` contiene una carpeta qu se llamará `projects`, en ella estarán todos los proyectos que vayamos a manejar en la asignatura. Por cada ejercicio, un proyecto.
- Dentro de esa carpeta habrá:
    - Un fichero llamado (el nombre da igual) `projects.code-workspace`. Este fichero nos define cómo está el *workspace* de VSCode y que, básicamente, indica qué directorios nos muestra el explorador de archivos. Al arrancar VSCode abrimos el workspace. Para abrirlo: `File-->Open Workspace from File...` y seleccionamos el fichero `projects.code-workspace`.
    - Directorios con los códigos fuentes de los proyectos.
 - Una carpeta por cada proyecto con el que estemos trabajando. El proyecto en sí no es nada, sino un conjunto de códigos estructurados. La estructura de un proyecto será como sigue:
    - Una carpeta (oculta si la miramos en el navegador de archivos del SO) llamada .vscode. Esta carpeta contiene dos ficheros que, a priori, no hay que modificar. 
        - `launch.json`: contiene toda la configuración para depuración independiente del SO
        - `tasks.json`: contiene toda la configuración para compilación y limpieza de ficheros compilados independiente del SO
    - Una carpeta llamada `includes` donde se alojarán los ficheros `.h` de nuestro código
    - Una carpeta llamada `lib` donde se alojarán librerías específicas de la aplicación o códigos particulares que no dependan de controladores del SO. Generalmente estará vacía.
    - Una carpeta llamada `output` donde se alojará el **fichero binario (ejecutable), que es el programa de nuestro proyecto. Tendrá el nombre de la carpeta: `project_name`.**
    - Una carpeta llamada `src` donde se alojarán los ficheros `.c` de nuestro código. Pudiera darse el caso de que dentro haya más carpetas, si fuese necesario estructurar el código así. El código será independiente de que se compile contra una placa u otra, o contra el PC.    
    - Un fichero `Makefile` con las reglas de compilación. Tendrá reglas para compilar cruzado o nativo (cuando no se trabaje con la placa de microcontrolador).
    - Al compilar (escribiendo `make` en una terminal, o dando a `Run-->Build Task`, o pulsando `Ctrl+Shift+B`), se generará guardará en la carpeta `output` el fichero ejecutable.
