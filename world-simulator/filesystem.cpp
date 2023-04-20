#include "World.h"
#pragma warning(disable : 4996)

void World::SaveToFile() {
	string fileName = controller->GetFileName();

	FILE* file = fopen(fileName.c_str(), "w");

	fwrite(&height, sizeof(int), 1, file);
	fwrite(&width, sizeof(int), 1, file);

	fwrite(organisms, sizeof(organisms), 1, file);
	fwrite(&player, sizeof(player), 1, file);

	fclose(file);

}

void World::LoadFromFile() {
	string fileName = controller->GetFileName();
}
