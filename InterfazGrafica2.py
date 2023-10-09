import tkinter as tk
from tkinter import ttk
from PIL import Image, ImageTk

# Función para cargar imágenes desde archivos
def cargar_imagen(ruta):
    imagen = Image.open(ruta)
    imagen = ImageTk.PhotoImage(imagen)
    return imagen

# Funciones de interacción para las pestañas con botones
def interactuar_1():
    label_info.config(text="Botón 1 presionado")

def interactuar_2():
    label_info.config(text="Botón 2 presionado")

# Crear la ventana principal
ventana = tk.Tk()
ventana.title("Interfaz con 5 Pestañas")

# Crear el controlador de pestañas
pestañas = ttk.Notebook(ventana)

# Pestaña 1 con imagen
pestaña1 = ttk.Frame(pestañas)
pestañas.add(pestaña1, text="Pestaña 1")

imagen1 = cargar_imagen("imagen1.jpg")
label1 = tk.Label(pestaña1, image=imagen1)
label1.pack()

# Pestaña 2 con imagen
pestaña2 = ttk.Frame(pestañas)
pestañas.add(pestaña2, text="Pestaña 2")

imagen2 = cargar_imagen("imagen2.jpg")
label2 = tk.Label(pestaña2, image=imagen2)
label2.pack()

# Pestaña 3 con botones
pestaña3 = ttk.Frame(pestañas)
pestañas.add(pestaña3, text="Pestaña 3")

boton1 = tk.Button(pestaña3, text="Botón 1", command=interactuar_1)
boton1.pack()
boton2 = tk.Button(pestaña3, text="Botón 2", command=interactuar_2)
boton2.pack()

# Pestaña 4 con botones
pestaña4 = ttk.Frame(pestañas)
pestañas.add(pestaña4, text="Pestaña 4")

boton3 = tk.Button(pestaña4, text="Botón 3", command=interactuar_1)
boton3.pack()
boton4 = tk.Button(pestaña4, text="Botón 4", command=interactuar_2)
boton4.pack()

# Pestaña 5 con una imagen adicional
pestaña5 = ttk.Frame(pestañas)
pestañas.add(pestaña5, text="Pestaña 5")

imagen3 = cargar_imagen("imagen3.jpg")
label3 = tk.Label(pestaña5, image=imagen3)
label3.pack()

# Etiqueta para mostrar información de botones
label_info = tk.Label(ventana, text="")
label_info.pack()

# Empacar el controlador de pestañas
pestañas.pack()

# Iniciar el bucle principal
ventana.mainloop()
