import java.io.*;
import java.net.*;

class ServerThread2 extends Thread {
    private Socket dataSocket;
    ObjectInputStream serverInputStream;
    ObjectOutputStream serverOutputStream;
    private static final String EXIT = "!";

    public ServerThread2(Socket socket)
    {
        dataSocket = socket;
        try {
        	serverInputStream  = new ObjectInputStream(socket.getInputStream());
        	serverOutputStream  = new ObjectOutputStream(socket.getOutputStream());
        	
        }
        catch(IOException e) {
            System.out.println("I/O Error " + e);
        }
    }

    public void run() {
        String inmsg, outmsg;

        try {
            ServerProtocol app = new ServerProtocol();
            Request req = (Request) serverInputStream.readObject();
            Reply rep = app.processRequest(req);
            while(!EXIT.equals(inmsg)) {
                outmsg = app.processRequest(inmsg);
                out.println(outmsg);
                inmsg = in.readLine();
            }
            dataSocket.close();
        }
        catch (IOException e) {
            System.out.println("I/O Error --> " + e);
        }
    }
}