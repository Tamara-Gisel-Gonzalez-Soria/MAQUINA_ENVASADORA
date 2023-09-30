import tkinter as tk
from tkinter import ttk

def contenido_pestaña1():
    label1 = ttk.Label(tab1, text="SIMULACION DE LLENADO")
    label1.grid(column=0, row=0, padx=200, pady=200)


def contenido_pestaña2():
    label2 = ttk.Label(tab2, text="REGISTROS DEL PROCESO")
    label2.grid(column=0, row=0, padx=200, pady=200)

def contenido_pestaña3():
    label3 = ttk.Label(tab3, text="AYUDA DE COMO INTERACTUAR")
    label3.grid(column=0, row=0, padx=200, pady=200)

def contenido_pestaña4():
    label4 = ttk.Label(tab4, text="MENÚ DE INICIO")
    label4.grid(column=0, row=0, padx=200, pady=200)

def contenido_pestaña5():
    label5 = ttk.Label(tab5, text="SALIR DE LA APLICACIÓN")
    label5.grid(column=0, row=0, padx=200, pady=200)

# Configuración de la ventana principal
root = tk.Tk()
root.title("Programa con Pestañas")

# Creación de las pestañas
tab_control = ttk.Notebook(root)

tab1 = ttk.Frame(tab_control)
tab2 = ttk.Frame(tab_control)
tab3 = ttk.Frame(tab_control)
tab4 = ttk.Frame(tab_control)
tab5 = ttk.Frame(tab_control)

tab_control.add(tab1, text="MARCHA")
tab_control.add(tab2, text="REGISTROS")
tab_control.add(tab3, text="AYUDA")
tab_control.add(tab4, text="MENÚ")
tab_control.add(tab5, text="EXIT")

# Añadir contenido a las pestañas
contenido_pestaña1()
contenido_pestaña2()
contenido_pestaña3()
contenido_pestaña4()
contenido_pestaña5()

# Empacar las pestañas
tab_control.pack(expand=1, fill="both")

# Iniciar el bucle principal
root.mainloop()
