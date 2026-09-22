using System;
using System.Messaging;
class Program
{
    static void Main()
    {
        // Ruta de la cola privada local
        string rutaCola = @".\Private$\ColaIPC";
        // Crear la cola si no existe
        if (!MessageQueue.Exists(rutaCola))
        {
            MessageQueue.Create(rutaCola);
            Console.WriteLine("Cola creada con éxito.");
        }
        // Conectar a la cola y enviar el mensaje
        using (MessageQueue cola = new MessageQueue(rutaCola))
        {
            string mensajeTexto = "Hola desde el proceso Emisor! - " +
            DateTime.Now.ToString();
            // Enviamos el objeto. MSMQ lo serializará automáticamente.
            cola.Send(mensajeTexto, "EtiquetaMensaje");
            Console.WriteLine($"Mensaje enviado: '{mensajeTexto}'");
        }
        Console.ReadLine();
    }
}