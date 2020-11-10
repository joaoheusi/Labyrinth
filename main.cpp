// Your First C++ Program

#include <iostream>
#include <string>


    int x_pos = 0;
    int y_pos = 0;
    int matrix[12][12];


    struct retVals {   
      int new_x_pos, new_y_pos;
    };

    retVals newTurn(int matrix[][12] ,int x_pos, int y_pos){
        bool S = false;
        bool N = false;
        bool W = false;
        bool E = false;
        std::string options = "Escolha seu movimento (Digite a letra):\n";

        if(matrix[x_pos-1][y_pos]!=1){
            N = true;
        }
        if(matrix[x_pos+1][y_pos]!=1){
            S = true;
        }
        if(matrix[x_pos][y_pos+1]!=1){
            E = true;
        }
        if(matrix[x_pos][y_pos-1]!=1){
            W = true;
        }

        if(W){
            options += "W) Oeste\n";
        }
        if(E){
            options += "E) Leste\n";
        }
        if(S){
            options += "S) Sul\n";
        }
        if(N){
            options += "N) Norte\n";
        }

        std::cout << options;

        retVals new_positions;
        std::string selection = "0";
        do
        {   
            std::cin >> selection;
            if(selection=="W" && W==true){
                selection = "W";
            }else
            if(selection=="N" && N==true){
                selection = "N";
            }else
            if(selection=="E" && E==true){
                selection = "E";          
            }else
            if(selection=="S" && S==true){
                selection = "S";
            }else{
                std::cout<< "Digite uma opção valida, LETRAS MAIUSCULAS.\n";
                selection = "0";
            }

        } while (selection != "W" && selection != "S" && selection != "N" && selection != "E");

        if(selection=="N"){
            new_positions = { x_pos-1, y_pos};
            return new_positions;
        }
        else if(selection=="S"){
            new_positions = { x_pos+1, y_pos};
            return new_positions;
        }
        else if(selection=="E"){
            new_positions = { x_pos, y_pos+1};
            return new_positions;
        }
        else {
            new_positions = { x_pos, y_pos-1};
            return new_positions;
        };
        /* std::cout<< new_positions.new_x_pos;
        std::cout<< new_positions.new_y_pos; */
        
    };



int main() {




    int a[12][12] = {

    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 5, 1, 9, 0, 0, 0, 0, 0, 0, 0, 17},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 7, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1},
    {1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 1, 3, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    
    };
    bool game = true;
    int player_position[] = {10,1};
    retVals new_positions;
    do
    {
        for (size_t i = 0; i < 12; i++)
        {
            for (size_t j = 0; j < 12; j++)
            {
                if (a[i][j]==1)
                {
                    std::cout << "###";

                }
                else if (i == player_position[0] && j == player_position[1] )
                {
                    std::cout << " x ";
                }
                
                else
                {
                    std::cout << "   ";
                }


            }

            std::cout << "\n";

        }

        new_positions = newTurn(a,player_position[0],player_position[1]);
        player_position[0] = new_positions.new_x_pos;
        player_position[1] = new_positions.new_y_pos;

        if (a[player_position[0]][player_position[1]]== 17){
            game= false;
            std::cout<< "Você ganhou o jogo, Parabéns clap clap clap.\n";
        }

        if (a[player_position[0]][player_position[1]]== 3 ||a[player_position[0]][player_position[1]]== 5 ||a[player_position[0]][player_position[1]]== 7 ||a[player_position[0]][player_position[1]]== 9){
            game= false;
            std::cout<< "VOCÊ FOI COMIDO SEM MASSAGEM, TENTE NOVAMENTE.\n";
        }

    } while (game==true);
    


}