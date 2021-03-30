import java.io.*;

public class OSProcess {
	public static void main (String[] args) throws IOException {
		if(args.length != 1) {
			System.err.println("Uso: java OSProcess <comando>");	
			System.exit(0);
		}

		// args[0] é o comando
		ProcessBuilder pb = new ProcessBuilder(args[0]); // Recebe um único argumento... Buscar outro construtor
		Process proc = pb.start();

		// obtém o fluxo de entrada
		InputStream is = proc.getInputStream();
		InputStreamReader isr = new InputStreamReader(is);
		BufferedReader br = new BufferedReader(isr);

		// lê o que é retornado pelo comando
		String line;
		while((line = br.readLine()) != null)
			System.out.println(line);

		br.close();
	}
}
