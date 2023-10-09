import tkinter as tk
from tkinter import ttk
from PIL import Image, ImageTk

class SimulacionLlenadoBotella:
    def __init__(self, root):
        self.root = root
        self.root.title("Simulación de Llenado de Botella")

        self.botella_frame = ttk.Frame(root)
        self.botella_frame.pack(pady=20)

        # Inicializa la botella con la imagen vacía
        self.botella_image = Image.open("botella_0.png")
        self.botella_photo = ImageTk.PhotoImage(self.botella_image)
        self.botella_label = ttk.Label(self.botella_frame, image=self.botella_photo)
        self.botella_label.pack()

        self.control_frame = ttk.Frame(root)
        self.control_frame.pack()

        self.start_button = ttk.Button(self.control_frame, text="Iniciar Llenado", command=self.iniciar_llenado)
        self.start_button.grid(row=0, column=0, padx=10)

        self.pause_button = ttk.Button(self.control_frame, text="Pausar", command=self.pausar_llenado)
        self.pause_button.grid(row=0, column=1, padx=10)
        self.pause_button["state"] = "disabled"

        self.stop_button = ttk.Button(self.control_frame, text="Detener", command=self.detener_llenado)
        self.stop_button.grid(row=0, column=2, padx=10)
        self.stop_button["state"] = "disabled"

        self.fill_percentage = 0  # Porcentaje de llenado actual

    def iniciar_llenado(self):
        self.start_button["state"] = "disabled"
        self.pause_button["state"] = "active"
        self.stop_button["state"] = "active"

        for i in range(1, 6):  # Simulación de llenado gradual en 5 etapas
            self.fill_percentage = i * 20
            imagen_botella = f"botella_{self.fill_percentage}.png"
            self.botella_image = Image.open(imagen_botella)
            self.botella_photo = ImageTk.PhotoImage(self.botella_image)
            self.botella_label.config(image=self.botella_photo)
            self.root.update_idletasks()
            self.root.after(1000)  # Espera 1 segundo entre cada etapa

        self.start_button["state"] = "active"
        self.pause_button["state"] = "disabled"
        self.stop_button["state"] = "disabled"

    def pausar_llenado(self):
        self.start_button["state"] = "active"
        self.pause_button["state"] = "disabled"
        self.stop_button["state"] = "active"

    def detener_llenado(self):
        self.fill_percentage = 0
        self.botella_image = Image.open("botella_0.png")
        self.botella_photo = ImageTk.PhotoImage(self.botella_image)
        self.botella_label.config(image=self.botella_photo)
        self.start_button["state"] = "active"
        self.pause_button["state"] = "disabled"
        self.stop_button["state"] = "disabled"

if __name__ == "__main__":
    root = tk.Tk()
    app = SimulacionLlenadoBotella(root)
    root.mainloop()