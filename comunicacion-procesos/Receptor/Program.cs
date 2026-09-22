using System;
using System.Messaging;

class Receptor
{
    static void Main()
    {
        string rutaCola = @".\Private$\ColaIPC";

        if (!MessageQueue.Exists(rutaCola))
        {
            Console.WriteLine("La cola aún no existe. Ejecuta el Emisor primero.");
            return;
        }

        using (MessageQueue cola = new MessageQueue(rutaCola))
        {
            // IMPORTANTE: Definir el formateador para decirle a MSMQ cómo
            // deserializar el contenido
            cola.Formatter = new XmlMessageFormatter(new Type[] { typeof(string) });

            Console.WriteLine("Esperando mensajes en la cola...");

            // El método Receive() bloquea el proceso hasta que llegue un mensaje
            Message mensaje = cola.Receive();


            string contenido = (string)mensaje.Body;
            Console.WriteLine($"Mensaje recibido: '{contenido}'");
        }
    }
}
