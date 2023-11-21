#include <stdio.h>
#include <string.h>

struct Song{
    char name[100];
    char artist[100];
    int duration;
};

struct Playlist{
    char name[100];
    Song songs[100]; // manggil struct Song (bisa juga ditulis struct Song songs[100])
    int songCount;
};
Playlist playlists[100];

int playlistCount = 0;

int lookupExistingPlaylist(char lookupPlaylist[]){
    // binary search
    // 1. left, right, mid
    int left = 0;
    int right = playlistCount - 1;
    int mid = 0;

    // 2. cari datanya sampai left > right
    while (left <= right) {
        mid = (left + right) / 2;
        // 2.1. cek datanya sama atau tidak
        if (strcmp(playlists[mid].name, lookupPlaylist) == 0) {
            return mid;
        }
        // 2.2. perkecil scope
        // 2.2.1. gerak ke kiri saat pencarian < nilai mid
        if (strcmp(lookupPlaylist, playlists[mid].name) < 0){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

void importSongData(){
    // baca file nya dulu
    // 1. buka file nya
    FILE *fd = fopen("songs.txt", "r");

    // 2.1 baca isi filenya sampai selesai (EOF)
    while (!feof(fd)){
        char songname[100];
        char songartist[100];
        int songduration;
        char playlistname[100];
        fscanf(fd, "%[^#]#%[^#]#%d#%[^\n]\n", songname, songartist, &songduration, playlistname);

        // 2.2. masukkin datanya ke dalam variable dari struct yang terbuat
        // 2.2.0. cek apakah sudah ada playlist yang dibaca
        Playlist newPlaylist;
        int searchIndex = lookupExistingPlaylist(playlistname);
        if (searchIndex != -1){
            // ambil playlist yang ada
            newPlaylist = playlists[searchIndex];
        } else {
            // 2.2.1. masukkin data playlist dulu
            strcpy(newPlaylist.name, playlistname);
            newPlaylist.songCount = 0;
        }

        // 2.2.2. masukkin data song nya kedalam playlist
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
        } else {
            playlists[searchIndex] = newPlaylist;
        }
    }
}

void swapSong(Song arrSong[], int a, int b){
    Song temp;
    strcpy(temp.name, arrSong[a].name);
    strcpy(temp.artist, arrSong[a].artist);
    temp.duration = arrSong[a].duration;

    arrSong[a] = arrSong[b];
    arrSong[b] = temp;
}

int partition(Song arrSong[], int left, int right){
    Song pivotSong = arrSong[right];

    int j = left;
    int i = left - 1;

    while (j < right){
        if (strcmp(arrSong[j].name, pivotSong.name) < 0){
            i++;
            swapSong(arrSong, i, j);
        }
        j++;
    }

    // tuker pivot dengan i+1
    swapSong(arrSong, i + 1, right);
    return (i + 1);
}

void quickSortSong(Song arrSong[], int left, int right){
    if (left >= right)
        return;

    // untuk ambil partition
    int pos = partition(arrSong, left, right);

    quickSortSong(arrSong, left, pos - 1);
    quickSortSong(arrSong, pos + 1, right);
}

// MERGE SORTING
void merge(int left, int mid, int right){
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    Playlist arrLeft[leftSize], arrRight[rightSize];
    for (int i = 0; i < leftSize; i++){
        arrLeft[i] = playlists[i + left];
    }
    for (int i = 0; i < rightSize; i++){
        arrRight[i] = playlists[i + mid + 1];
    }

    int leftCount = 0, rightCount = 0, mergeCount = left;

    while (leftCount < leftSize && rightCount < rightSize){
        if (strcmp(arrLeft[leftCount].name, arrRight[rightCount].name) < 0){
            playlists[mergeCount] = arrLeft[leftCount];
            leftCount++;
        } else {
            playlists[mergeCount] = arrRight[rightCount];
            rightCount++;
        }
        mergeCount++;
    }
    while (leftCount < leftSize){
        playlists[mergeCount] = arrLeft[leftCount];
        leftCount++;
        mergeCount++;
    }
    while (right > rightSize){
        playlists[mergeCount] = arrRight[rightCount];
        rightCount++;
        mergeCount++;
    }
}

// MERGE SORT
void mergeSortPlaylist(int left, int right){
    int mid = (left + right) / 2;

    if (left >= right){
        return;
    }

    mergeSortPlaylist(left, mid);
    mergeSortPlaylist(mid + 1, right);
    merge(left, mid, right);
}

void insertMenu(){
    char songName[100], songArtis[100], playlistName[100];
    int songDuration = 0;

    do{
        printf("Song name [must not be empty]: ");
        scanf("%[^\n]", songName);
        getchar();
    } while (strlen(songName) <= 0);

    do{
        printf("Song artist [must not be empty]: ");
        scanf("%[^\n]", songArtis);
        getchar();
    } while (strlen(songArtis) <= 0);

    do{
        printf("Song duration (in seconds) [must be more than 0]: ");
        scanf("%d", &songDuration);
        getchar();
    } while (songDuration <= 0);

    do{
        printf("Playlist name [must not be empty]: ");
        scanf("%[^\n]", playlistName);
        getchar();
    } while (strlen(playlistName) <= 0);

    Playlist newPlaylist;

    // cari apakah playlistnya sudah ada apa belum
    int searchIndex = lookupExistingPlaylist(playlistName);

    // kalau ketemu
    if (searchIndex != -1){
        newPlaylist = playlists[searchIndex];
    } else {     // kalau tidak ketemu
        strcpy(newPlaylist.name, playlistName);
        newPlaylist.songCount = 0;
    }

    Song newSong;
    strcpy(newSong.name, songName);
    strcpy(newSong.artist, songArtis);
    newSong.duration = songDuration;

    newPlaylist.songs[newPlaylist.songCount] = newSong;
    newPlaylist.songCount++;

    quickSortSong(newPlaylist.songs, 0, newPlaylist.songCount - 1);

    // kalau dia playlist baru kita masukkan playlist baru kedalam array playlists
    if (searchIndex != -1){
        playlists[searchIndex] = newPlaylist;
    } else {
        playlists[playlistCount] = newPlaylist;
        playlistCount++;
    }
}

void viewAll(){
    for (int i = 0; i < playlistCount; i++){
        printf("Playlist: %s\n", playlists[i].name);

        // setiap playlist yang ada, print song nya
        for (int j = 0; j < playlists[i].songCount; j++)
        {
            printf(" | %s | %s | %d |\n", playlists[i].songs[j].name, playlists[i].songs[j].artist, playlists[i].songs[j].duration);
        }
    }
}

int main(){

    importSongData();
    viewAll();
    insertMenu();
    viewAll();

}