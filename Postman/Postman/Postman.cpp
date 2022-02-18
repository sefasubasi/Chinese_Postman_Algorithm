#include <iostream>
#include<list>
using namespace std;

class graph {
public:
    list<int>* liste;
    int n;
    graph(int v) {
        liste = new list<int>[v];
        n = v;

    }

    void addedge(int u, int v) {
        liste[u].push_back(v);
        liste[v].push_back(u);
    }

    void goster()
    {
        int dizi[5][5];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 5; j++)
                dizi[i][j] = 0;

        }
        cout << "Dugum Baglantilari" << endl;
        for (int i = 1; i < n; i++) {
            cout << i << "-->";
            for (auto it : liste[i]) {
                cout << it << " ";
                if (dizi[i][it] > 0)
                    dizi[i][it] += dizi[i][it];
                else
                    dizi[i][it] = 1;
            }
            cout << endl;
        }

        cout << endl;
        cout << endl;
        cout << "Graph'in Matris Tablosu" << endl;
        cout << "  ";
        for (int i = 1; i < n; i++)
            cout << i << " ";
        cout << endl;
        for (int i = 1; i < n; i++)
        {
            cout << i << " ";
            for (int j = 1; j < n; j++)
                cout << dizi[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        int derece[5] = { 0,0,0,0,0 };
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                derece[i] += dizi[i][j];
            }
        }
        for (int i = 1; i < n; i++)
            cout << i << ".dugumun derecesi =" << derece[i] << endl;


        for (int i = 1; i < n; i++)
        {
            if (derece[i] % 2 == 1)
            {

                int sayi = 1;
            back:
                int sayac = 1;
                for (int j = sayi; j < n; j++)
                {
                    if (i != j)
                    {
                        dizi[i][j] += 1;
                        dizi[j][i] += 1;
                        derece[i] += 1;
                        derece[j] += 1;
                        for (int x = 1; x < n; x++)
                        {
                            if (derece[x] % 2 == 1) {
                                dizi[i][j] -= 1;
                                dizi[j][i] -= 1;
                                derece[i] -= 1;
                                derece[j] -= 1;
                                sayi++;
                                goto back;

                            }
                            else
                                sayac++;
                            if (sayac > 2)
                            {
                                liste[i].push_back(j);
                                liste[j].push_back(i);
                                cout << endl;
                                cout << i << "," << j << " Kenarina yeni yol eklenmistir." << endl;
                                break;
                            }

                        }
                    }

                }
            }

        }
        cout << endl;
        for (int i = 1; i < n; i++)
            cout << i << ".dugumun derecesi =" << derece[i] << endl;
        cout << "Tum dugum dereceleri cift oldugundan Euler Dongusu tamamlandi. Chinese Postman Algoritamsi olusturuldu." << endl;

        cout << endl;
        cout << endl;
        cout << "Yeni Graph'in Matris Tablosu" << endl;
        cout << "  ";
        for (int i = 1; i < n; i++)
            cout << i << " ";
        cout << endl;
        for (int i = 1; i < n; i++)
        {
            cout << i << " ";
            for (int j = 1; j < n; j++)
                cout << dizi[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        cout << "Dugum Baglantilarinin Son Hali" << endl;
        for (int i = 1; i < n; i++) {
            cout << i << "-->";
            for (auto it : liste[i]) {
                cout << it << " ";
                if (dizi[i][it] > 0)
                    dizi[i][it] += dizi[i][it];
                else
                    dizi[i][it] = 1;
            }
            cout << endl;
        }
    }


};

int main() {
    graph g(5);
    g.addedge(1, 2);
    g.addedge(2, 3);
    g.addedge(3, 4);
    g.addedge(3, 4);
    g.addedge(4, 1);
    g.addedge(4, 1);
    g.addedge(2, 4);

    g.goster();
}