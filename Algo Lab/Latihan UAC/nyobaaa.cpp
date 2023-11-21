#include<stdio.h>
#include<string.h>

struct Song{
	char name[100];
	char artist[100];
	int duration;
};

struct Playlist{
	char name [100];
	Song songs[100];
	int songCount;
} playlists[100];

int playlistCount = 0;

int lookupExistingPlaylist(char lookupPlaylist[]){
	// binary search
	// 1.kita butuh left, right, mid	
	int left = 0;
	int right = playlistCount - 1;
	int mid = 0;
	// printf("%d - %d\n", left , right);
	// 2. cari datanya sampai left > right
	while (left <= right){
		mid = (left + right)/2;
		// printf("%s\n", playlists[mid].name);
		// 2.1. cek datanya sama atau tidak
		if (strcmp(playlists[mid].name, lookupPlaylist) == 0){
			return mid;
		}
		
		// 2.2. perkecil scope
		// 2.2.1/ gerak ke kiri saat pencarian < nilai mid
		if (strcmp(lookupPlaylist, playlists[mid].name) < 0){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
	return -1;
}

void importSongData(){
	// baca file nya dulu
	// 1. buka file nya
	FILE* fd = fopen("songs.txt", "r");
	
	// 2. baca isi filenya sampai selesai (EOF)
	while (!feof(fd))
	{
		// 2.1. ambil datanya menggunakan fscanf
		char songname[100];
		char songartist[100];
		int songduration;
		char playlistname[100];
		fscanf(fd, "%[^#]#%[^#]#%d#%[^\n]\n", songname, songartist, &songduration, playlistname);
		
		// 2.2. masukin datanya ke dalam variable dari struct yang terbuat
		
		// 2.2.0. cek apakah sudah ada playlist yang dibaca
		Playlist newPlaylist;
		int searchIndex = lookupExistingPlaylist(playlistname);
//		printf("%d", searchIndex);
		if (searchIndex != -1){
			// ambil playlist yang ada 
			newPlaylist = playlists[searchIndex];
		}else{
			// 2.2.1. masukin data playlist dulu
			strcpy(newPlaylist.name, playlistname);
			newPlaylist.songCount = 0;	
		}
			
		// 2.2.2. masukin data song nya ke dalam playlist
		Song newSong;
		strcpy(newSong.name, songname);
		strcpy(newSong.artist, songartist);
		newSong.duration = songduration;
		
		newPlaylist.songs[newPlaylist.songCount] = newSong;
		newPlaylist.songCount++;
		
		// 2.2.3. masukkin playlist baru ke dalam data playlist yang dipunyai
		if (searchIndex == -1){
			playlists[playlistCount] = newPlaylist;
			playlistCount++;	
		}else {
			playlists[searchIndex] = newPlaylist;
		}	
	}
}

void swapSong(Song arrSong[], int a, int b)
{
	Song temp;
	strcpy(temp.name, arrSong[a].name);
	strcpy(temp.artist, arrSong[a].artist);
	temp.duration = arrSong[a].duration;
	
	arrSong[a] = arrSong[b];
	arrSong[b] = temp;
}


int partition(Song arrSong[], int left, int right)
{
	Song pivotSong = arrSong[right];
	
	int i = left - 1;
	int j = left;
	
	while (j < right)
	{
		if(strcmp(arrSong[j].name, pivotSong.name) < 0)
		{
			i++;
			swapSong(arrSong, i, j);
		}
		j++;
	}
	
	swapSong(arrSong, i+1, right);
	return (i+1);
}

void quickSortSong(Song arrSong[], int left, int right)
{
	if(left >= right) return;
	
	int position = partition(arrSong, left, right);
	
	quickSortSong(arrSong, left, position-1);
	quickSortSong(arrSong, position+1, right);
}

void swapPlaylist(int l, int r){ 
	Playlist temp;
	temp = playlists[l]; 	 
	playlists[l] = playlists[r]; 
	playlists[r] = temp; 		
}

int partitions(Playlist list[],int left, int right){ 
	Playlist pivot_playlist = list[right]; 
	int i = left - 1;  
	int j  = left;
	while(j < right){ 
		if(strcmp(playlists[j].name,pivot_playlist.name) < 0){ 
			i++;
			swapPlaylist(i, j);
		}
		j++;
	}
	swapPlaylist(i + 1, j);
	return (i + 1); 
}

void quick_playlist(int l, int r){ 
	if(l < r){ 
		int part = partitions(playlists,l,r);
		quick_playlist(l, part -1); 
		quick_playlist(part + 1, r); 
	}
}

void insertMenu()
{
	char songName[255] = {};
	char songArtist[255] = {};
	char playlistName[255] = {};
	int duration;
	
	do
	{
		printf("Input Song Name: ");
		scanf("%[^\n]", songName);
		getchar();
	}
	while (strlen(songName) <= 0);
	
	do
	{
		printf("Input Song Artist: ");
		scanf("%[^\n]", songArtist);
		getchar();
	}
	while (strlen(songArtist) <= 0);
	
	do
	{
		printf("Input Song Duration: ");
		scanf("%d", &duration);
		getchar();
	}
	while(duration <= 0);
	
	do 
	{
		printf("Input Song Playlist: ");
		scanf("%[^\n]", playlistName);
		getchar();
	}
	while (strlen(playlistName) <= 0);
	
	Playlist newPlaylist;
	
	// cari apakah playlistnya sudah ada atau belum
	int searchIndex = lookupExistingPlaylist(playlistName);
	
	// kalo ketemu
	if (searchIndex != -1)
	{
		newPlaylist = playlists[searchIndex];
	}
	// kalo tidak ketemu
	else
	{
		strcpy(newPlaylist.name, playlistName);
		newPlaylist.songCount = 0;
	}
	
	Song newSong;
	strcpy(newSong.name, songName);
	strcpy(newSong.artist, songArtist);
	newSong.duration = duration;
	
	newPlaylist.songs[newPlaylist.songCount] = newSong;
	newPlaylist.songCount++;
	
	quickSortSong(newPlaylist.songs, 0, newPlaylist.songCount-1);
	
	if(searchIndex != -1)
	{
		playlists[searchIndex] = newPlaylist;
	}
	else
	{
		playlists[playlistCount] = newPlaylist;
		playlistCount++;
		quick_playlist(0, playlistCount-1);
	}
}

void viewAll()
{
	for(int i = 0; i < playlistCount; i++)
	{
		printf("Playlist: %s\n", playlists[i].name);
		
		// setiap playlist yang ada, print song nya
		for (int j = 0; j < playlists[i].songCount; j++)
		{
			printf("    | %s | %s | %d |\n", playlists[i].songs[j].name, playlists[i].songs[j].artist, playlists[i].songs[j].duration);
		}
	}
}

void menu ()
{
	int input;
	
	do
	{
		printf("Song Player\n");
		printf("============\n");
		printf("1. Add new song\n");
		printf("2. Show all songs\n");
		printf("3. Search song(s)\n");
		printf("4. Exit\n");
		printf("Choose >>\n");
		scanf("%d", &input);
		getchar();		
		
		if (input == 1)
		{
			insertMenu();
		}

		if (input == 2)
		{
			viewAll();
		}	
	}
	while (input != 4);
}

int main()
{
	importSongData();
//	mergeSortPlaylist(0, playlistCount-1);
//	for (int i = 0; i < playlistCount; i++)
//	{
//		quickSortSong(playlists[i].songs, 0, playlists[i].songCount-1);
//	}
	menu();
//	importSongData();
//	viewAll();
//	insertMenu();
//	viewAll();
	return 0;
}
