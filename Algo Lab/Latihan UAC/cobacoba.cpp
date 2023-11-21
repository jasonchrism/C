#include <stdio.h>
#include <string.h>

struct Song{
    char songName[100];
    char songArtist[100];
    int duration;
};

struct Playlist{
    char playlistName[100];
    Song songs[100];
    int songCount;
}playlists[100];

int playlistCount = 0;

int searchExist(char searchPl[]){
    if (playlistCount == 0) return -1;
    int left = 0;
    int right = playlistCount - 1;
    int mid;
    while (left <= right){
        mid = (left + right) / 2;
        if (strcmp(playlists[mid].playlistName, searchPl) == 0){
            return mid;
        } else if (strcmp(playlists[mid].playlistName, searchPl) < 0){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int partitionPlay(int low, int high){
    int i = low - 1;
    int j = low;
    char pivot[100];
    strcpy(pivot, playlists[high].playlistName);

    while (j < high){
        if (strcmp(playlists[j].playlistName, pivot) < 0){
            i++;
            Playlist temp = playlists[j];
            playlists[j] = playlists[i];
            playlists[i] = temp;
        }
        j++;
    }
    Playlist temp = playlists[i+1];
    playlists[i+1] = playlists[high];
    playlists[high] = temp;
    return (i+1);
}

void quickSortPlay(int low, int high){
    if (low < high){
        int pos = partitionPlay(0, playlistCount-1);
        quickSortPlay(low, pos - 1);
        quickSortPlay(pos + 1, high);
    }
}

int partitionSong(int low, int high, int search){
    int i = low - 1;
    int j = low;
    char pivotSong[100];
    strcpy(pivotSong, playlists[search].songs[high].songName);
    while (j < high){
        if (strcmp(playlists[search].songs[j].songName, pivotSong) < 0){
            i++;
            Song temp = playlists[search].songs[j];
            playlists[search].songs[j] = playlists[search].songs[i];
            playlists[search].songs[i] = temp;
        }
        j++;
    }
    Song temp = playlists[search].songs[i+1];
    playlists[search].songs[i+1] = playlists[search].songs[high];
    playlists[search].songs[high] = temp;
    return (i+1);
}

void quickSortSong(int low, int high, int search){
    if (low < high){
        int pos = partitionSong(0, high, search);
        quickSortSong(low, pos - 1, search);
        quickSortSong(pos + 1, high, search);
    }
}

void importData(){
    FILE* filePointer = fopen("nyoba.txt", "r");
    char name[100];
    char artist[100];
    int dura;
    char searchPl[100];
    while (!feof(filePointer)){
        fscanf(filePointer, "%[^#]#%[^#]#%d#%[^\n]", name, artist, &dura, searchPl);

        int search = searchExist(searchPl);
        if (search == -1){
            strcpy(playlists[playlistCount].playlistName, searchPl);
            strcpy(playlists[playlistCount].songs[0].songName, name);
            strcpy(playlists[playlistCount].songs[0].songArtist, artist);
            playlists[playlistCount].songs[0].duration = dura;
            playlists[playlistCount].songCount = 1;
            playlistCount++;
            quickSortPlay(0, playlistCount-1);
        } else {
            int last = playlists[search].songCount;
            strcpy(playlists[search].songs[last].songName, name);
            strcpy(playlists[search].songs[last].songArtist, artist);
            playlists[search].songs[last].duration = dura;
            playlists[search].songCount++;
            quickSortSong(0, playlists[search].songCount-1, search);
        }
    }
    fclose(filePointer);   
}

void addSong(){
    char songTitle[100];
    char songSinger[100];
    int durationSong;
    char playlistSong[100];

    do {
        printf("Song name [must not be empty]: ");
        scanf("%[^\n]", songTitle); getchar();
    } while (strlen(songTitle) <= 0);

    do {
        printf("Song artist [must not be empty]: ");
        scanf("%[^\n]", songSinger); getchar();
    } while (strlen(songSinger) <= 0);

    do {
        printf("Song duration (in seconds) [must be more than 0]: ");
        scanf("%d", &durationSong); getchar();
    } while (durationSong <= 0);

    do {
        printf("Playlist name [must not be empty]: ");
        scanf("%[^\n]", playlistSong); getchar();
    } while (strlen(playlistSong) <= 0);

    int search = searchExist(playlistSong);
    if (search == -1){
        strcpy(playlists[playlistCount].playlistName, playlistSong);
        strcpy(playlists[playlistCount].songs[0].songName, songTitle);
        strcpy(playlists[playlistCount].songs[0].songArtist, songSinger);
        playlists[playlistCount].songs[0].duration = durationSong;
        playlists[playlistCount].songCount = 1;
        playlistCount++;
        quickSortPlay(0, playlistCount-1);
    } else {
        int last = playlists[search].songCount;
        strcpy(playlists[search].songs[last].songName, songTitle);
        strcpy(playlists[search].songs[last].songArtist, songSinger);
        playlists[search].songs[last].duration = durationSong;
        playlists[search].songCount++;
        quickSortSong(0, playlists[search].songCount-1, search);
    }

    FILE* filePointer = fopen("nyoba.txt", "w");
    for (int i = 0; i < playlistCount; i++){
        for (int j = 0; j < playlists[i].songCount; j++){
            fprintf(filePointer, "%s#%s#%s#%d\n", playlists[i].playlistName, playlists[i].songs[j].songName, playlists[i].songs[j].songArtist, playlists[i].songs[j].duration);
        }
    }
    fclose(filePointer);
}

void viewAll(){
    for (int i = 0; i < playlistCount; i++){
        printf("Playlist : %s\n", playlists[i].playlistName);
        for (int j = 0; j < playlists[i].songCount; j++){
            printf("| %s | %s | %d sec |\n", playlists[i].songs[j].songName, playlists[i].songs[j].songArtist, playlists[i].songs[j].duration);
        }
    }
}

void findSong(){
    char find[100];
    printf("Song to search : ");
    scanf("%[^\n]", find); getchar();
    for (int i = 0; i < playlistCount; i++){
        for (int j = 0; j < playlists[i].songCount; j++){
            if (strstr(playlists[i].songs[j].songName, find)){
                printf("Playlist : %s\n", playlists[i].playlistName);
                printf("| %s - %s - %d\n", playlists[i].songs[j].songName, playlists[i].songs[j].songArtist, playlists[i].songs[j].duration);
            }
        }
    }
}

int main(){

    importData();
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
            addSong();
        }

        if (input == 2){
            viewAll();
        }

        if (input == 3){
            findSong();
        } 
    } while (input != 4);
}