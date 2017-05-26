#include <FS.h>

void setup() {
  /* Serial */
  Serial.begin(115200);

  /* SPIFFS */
  // Format FS, this will take some time. Only needed once.
  SPIFFS.format();
  // Begin SPIFFS
  SPIFFS.begin();
}

void loop() {
  // Create a bunch of new files
  for (int i = 0; i < 10; i++) {
    create_file("/", String(i), String(i * i * 100));
  }

  // Print all files created
  print_filesystem();

  // Delete them
  delete_filesystem();
}

void create_file(String folder, String name, String data) {
  // Filename must start with root dir /
  String filename = folder.charAt(0) == '/' ? "" : "/";
  filename += folder;
  // Check if folder has / at the end
  filename += filename.endsWith("/") ? "" : "/";
  filename += name;

  // Create File
  File new_file = SPIFFS.open(folder + name, "w+");
  // Print data into file and close
  new_file.print(data);
  new_file.close();
}

bool delete_file(String name) {
  return SPIFFS.remove(name);
}

bool delete_filesystem() {
  Dir dir = SPIFFS.openDir("/");
  bool allgood = true;
  while (dir.next()) {
    allgood &= delete_file(dir.fileName());
  }
  return allgood;
}

void print_filesystem() {
  Dir dir = SPIFFS.openDir("/");
  while (dir.next()) {
    Serial.print(dir.fileName());
    File f = dir.openFile("r");
    Serial.print(" - Size: "); Serial.println(f.size());
  }
}

