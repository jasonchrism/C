#include <stdio.h>
#include <string.h>

struct Song{
    char name[100];
    char artist[100];
    int duration;
};

struct Playlist{
    char name[100];
    Song songs[100];
    int songCount;
}playlists[100];

int playlistCount = 0; //hitung banyak data

int lookupExistingPlaylist(char lookupPlaylist[]){ //binary search
    int left = 0;
    int right = playlistCount - 1;
    int mid = 0;

    while (left <= right){ //cari data sampai left > right
        int mid = (left + right) / 2;
        if (strcmp(playlists[mid].name, lookupPlaylist) == 0){  //cek datanya sama atau tidak
            return mid;
        }
        //perkecil scope
        //gerak ke kiri saat search < mid
        if (strcmp(lookupPlaylist, playlists[mid].name) < 0){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

void importSongData(){
    FILE* filePointer = fopen("songs.txt", "r"); //buka file
    while (!feof(filePointer)){
        char songName[100];
        char songArtist[100];
        int songDuration;
        char playlistName[100];
        fscanf(filePointer, "%[^#]#%[^#]#%d#%[^\n]\n", songName, songArtist, &songDuration, playlistName); //ambil data menggunakan fscanf

        Playlist newPlaylist;
        int searchIndex = lookupExistingPlaylist(playlistName);
        if (searchIndex != -1){ //cek apakah sudah ada playlist yang dibaca
            newPlaylist = playlists[searchIndex];
        } else  {
            strcpy(newPlaylist.name, playlistName); //Masukkan data playlist
            newPlaylist.songCount = 0;
        }

        Song newSong;
        strcpy(newSong.name, songName); 
        strcpy(newSong.artist, songArtist); //Masukkan data song ke dalam playlist
        newSong.duration = songDuration; 
   
        newPlaylist.songs[newPlaylist.songCount] = newSong;
        newPlaylist.songCount++;

        playlists[playlistCount] = newPlaylist; //Masukkan playlist baru ke dalam data playlist yang dipunyai
        playlistCount++;

        //masukkan playlist baru ke dalam playlist
        if (searchIndex == -1){
            playlists[playlistCount] = newPlaylist;
            playlistCount++;
        } else {
            playlists[searchIndex] = newPlaylist;
        }
    }
}

void viewAll(){
    for (int i = 0; i < playlistCount; i++){
        printf("Playlist : %s\n", playlists[i].name); //looping untuk print playlist

        for (int j = 0; j < playlists[i].songCount; j++){
            printf("| %s | %s | %d |\n", playlists[i].songs[j].name, playlists[i].songs[j].artist, playlists[i].songs[j].duration);
        }
        puts("");
    }
}

int main(){

    importSongData();
    viewAll();

}