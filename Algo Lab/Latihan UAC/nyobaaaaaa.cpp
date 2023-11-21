#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Song{
	char songName[100];
	char songArtist[100];
	int duration;
};

struct Playlist{
	char playlistName[100];
	Song songs[100];
	int songCount = 0;
}playlists[100];

int playlistCount = 0;

int searchPlaylist(char searchPl[]){
	int left = 0;
	int right = playlistCount - 1;
	int mid;
	
	while (left <= right){
		mid = (left + right) / 2;
		if (strcmp(playlists[mid].playlistName, searchPl) == 0){
			return mid;
		} else if (strcmp(searchPl, playlists[mid].playlistName) < 0){
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return -1;
}

void importData(){
	FILE* filePointer = fopen("nyoba.txt", "r");
	while (!feof(filePointer)){
        char songname[100];
        char songartist[100];
        int duration1;
        char playlistt[100];
		fscanf(filePointer, "%[^#]#%[^#]#%d#%[^\n]\n", songname, songartist, &duration1, playlistt);
		
		Playlist newPlaylist;
		int searchIndex = searchPlaylist(playlistt);
		if (searchIndex != -1){
			newPlaylist = playlists[searchIndex];
 		} else {
 			strcpy(newPlaylist.playlistName, playlistt);
 			newPlaylist.songCount = 0;
		}
		
		Song newSong;
		strcpy(newSong.songName, songname);
		strcpy(newSong.songArtist, songartist);
		newSong.duration = duration1;
		
		newPlaylist.songs[newPlaylist.songCount] = newSong;
		newPlaylist.songCount++;
		
		if (searchIndex == -1){
			playlists[playlistCount] = newPlaylist;
			playlistCount++;
		} else {
			playlists[searchIndex] = newPlaylist;
		}
	}
}

void swapQuickSong(Song arrSong[], int a, int b){
	Song temp;
	strcpy(temp.songName, arrSong[a].songName);
	strcpy(temp.songArtist, arrSong[a].songArtist);
	temp.duration = arrSong[a].duration;
	
	arrSong[a] = arrSong[b];
	arrSong[b] = temp;
}

int partition(Song arrSong[], int left, int right){
	int i = left - 1;
	int j = left;
	Song pivot = arrSong[right];
	while (j < right){
		if (strcmp(arrSong[j].songName, pivot.songName) < 0){
			i++;
			swapQuickSong(arrSong, i, j);
		}
		j++;	
	}
	swapQuickSong(arrSong, i + 1, right);
	return (i+1);
}

void quickSortSong(Song arrSong[], int left, int right){
	if (left < right){
		int pos = partition(arrSong, left, right);
		quickSortSong(arrSong, left, pos - 1);
		quickSortSong(arrSong, pos + 1, right);
	}
}

void swapQuickPlay(Playlist arrPlay[], int a, int b){
	Playlist temp;
	strcpy(temp.playlistName, arrPlay[a].playlistName);
	
	arrPlay[a] = arrPlay[b];
	arrPlay[b] = temp;
}

int partitionPlay(Playlist arrPlay[], int left, int right){
	int i = left - 1;
	int j = left;
	Playlist pivot = arrPlay[right];
	while (j < right){
		if (strcmp(arrPlay[j].playlistName, pivot.playlistName) < 0){
			i++;
			swapQuickPlay(arrPlay, i, j);
		}
		j++;
	}	
	swapQuickPlay(arrPlay, i + 1, right);
	return (i+1);
}

void quickSortPlaylist(Playlist arrPlay[], int left, int right){
	if (left <= right){
		int pos = partitionPlay(arrPlay, left, right);
		quickSortPlaylist(arrPlay, left, pos - 1);
		quickSortPlaylist(arrPlay, pos + 1, right);
	}
}

void insert(){
	char name[100] = {};
	char artist[100] = {};
	char play[100] ={};
	int dur;
	
	do {
		printf("Song name [must not be empty]: ");
		scanf("%[^\n]", name); 
        getchar();
	} while (strlen(name) == 0);
	
	do {
		printf("Song artist [must not be empty]: ");
		scanf("%[^\n]", artist); getchar();
	} while (strlen(artist) == 0);
	
	do {
		printf("Song durationn (in seconds)  [must be more than 0]: ");
		scanf("%d", &dur); getchar();
	} while (dur == 0);
	
	do {
		printf("Playlist name [must not be empty]: ");
		scanf("%[^\n]", play); getchar();
	} while (strlen(play) == 0);
	printf("Added..."); getchar();
	
	Playlist newPlaylist;
	int searchIndex = searchPlaylist(play);
	if (searchIndex != -1){
		newPlaylist = playlists[searchIndex];
	} else {
		strcpy(newPlaylist.playlistName, play);
		newPlaylist.songCount = 0;
	}
	
	Song newSong;
	strcpy(newSong.songName, name);
	strcpy(newSong.songArtist, artist);
	newSong.duration = dur;
	
	newPlaylist.songs[newPlaylist.songCount] = newSong;
	newPlaylist.songCount++;
	
	quickSortSong(newPlaylist.songs, 0, newPlaylist.songCount-1);
	
	if (searchIndex != -1){
		playlists[searchIndex] = newPlaylist;
	} else {
		playlists[playlistCount] = newPlaylist;
		playlistCount++;
		quickSortPlaylist(playlists, 0, playlistCount-1);
	}
}

void viewAll(){
	for (int i = 0; i < playlistCount; i++){
		printf("Playlist : %s\n", playlists[i].playlistName);
		for (int j = 0; j < playlists[i].songCount; j++){
			printf("| %s | %s | %dseconds |\n", playlists[i].songs[j].songName, playlists[i].songs[j].songArtist, playlists[i].songs[j].duration);
		}
	}
}

void menu(){
	int input;
	do {
		puts("Song Player");
		puts("===========");
		puts("1. Add new song");
		puts("2. Show all songs");
		puts("3. Search song(s)");
		puts("4. Exit");
		printf("Choose >> ");
		scanf("%d", &input); getchar();
		
		if (input == 1){
			insert();
		}
		if (input == 2){
			viewAll();
		}	
	} while (input != 4);	
}

int main(){
	
    importData();
	viewAll();
	menu();
	
}