#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#define True 1;
#define False 0;
struct options
{
int r;
int s;
};
typedef struct options options;
options optionsmenu(SDL_Surface* screen, SDL_Surface* t1[],  SDL_Surface* image, SDL_Rect imagebg , TTF_Font* font,options op)
{
  op.r=0;
  op.s=1;
  Uint32 time;
  SDL_Rect  bgpos ;
  bgpos.x=0;
  bgpos.y=0;
  imagebg.x=250;
  imagebg.y=150;
  SDL_BlitSurface(image, NULL, screen, &bgpos);

int x,y,c=0;
if (op.r == 0 &&  op.s==0){
  SDL_BlitSurface( t1[3] ,NULL, screen, &imagebg );}
if (op.r == 1 &&  op.s==0){
  SDL_BlitSurface( t1[2] ,NULL, screen, &imagebg );}
if (op.r == 0 &&  op.s==1){
  SDL_BlitSurface( t1[5] ,NULL, screen, &imagebg );}
if (op.r == 1 &&  op.s==1){
  SDL_BlitSurface( t1[8] ,NULL, screen, &imagebg );}
SDL_Flip(screen);
SDL_Event event;
while(1)
{
  time = SDL_GetTicks();
  while(SDL_PollEvent(&event))
  {
    SDL_WaitEvent(&event);
    switch(event.type)
            {
                      case SDL_QUIT:
      return op;
                              break;
              case SDL_MOUSEMOTION:
                    x = event.motion.x;
                      y = event.motion.y;
                      if (op.r==0 && op.s==0) {
                        if(x>=150 && x<=300 && y>=200 && y<=300) {SDL_BlitSurface( t1[2] ,NULL, screen, &imagebg );  break;}
                    }
                            if (op.r==0 && op.s==1){
                              if(x>=150 && x<=300 && y>=200 && y<=300) {SDL_BlitSurface( t1[4] ,NULL, screen, &imagebg );  break;}

                                 }
                             if (op.r==1 && op.s==0){
                               if(x>=150 && x<=300 && y>=200 && y<=300) {SDL_BlitSurface( t1[6] ,NULL, screen, &imagebg );  break;}

                                  }
                                  if (op.r == 1 && op.s == 1){
                                    if(x>=355 && x<=440 && y>=388 && y<=426) {SDL_BlitSurface( t1[7] ,NULL, screen, &imagebg );  break;}

                                       }

                              break;
                              case SDL_MOUSEBUTTONDOWN:
                                        x = event.button.x;
                                      y = event.button.y;
                                      if (event.button.button == SDL_BUTTON_LEFT) {
                              if(x>=441 && x<=462 && y>=227 && y<=261)
                              {
                     if (op.r ==1 ) { op.r=0;
                       if (op.s == 0) {SDL_BlitSurface( t1[1] ,NULL, screen, &imagebg );  break;}
                       if (op.s == 1) {SDL_BlitSurface( t1[7] ,NULL, screen, &imagebg );  break;}
                             }
                              }
                              if(x>=567 && x<=590 && y>=227 && y<=260)
                              {
                                if (op.r ==0 ) { op.r=1;}
                                  break;
                              }
                              if(x>=440 && x<=462 && y>=435 && y<=381)
                              {
                                if (op.s ==1 ) { op.s=0;}
                                  break;
                              }
                              if(x>=567 && x<=590 && y>=347 && y<=380)
                              {
                                if (op.s ==0 ) { op.s=1;}
                                  break;
                              }
                              }
                              if(x>=355 && x<=440 && y>=388 && y<=426)
                              {
                              return op;
                                break;
                              }
                              break;

  }
                  SDL_Flip(screen);
            }
  }

}
int showmenu(SDL_Surface* screen, SDL_Surface* t[],SDL_Surface * image, SDL_Rect imagebg , TTF_Font* font, SDL_Surface* t1[])
{
  options op;
        Uint32 time;
        SDL_Rect  bgpos ;
        bgpos.x=0;
        bgpos.y=0;
        imagebg.x=image->w / 2 - 100;
        imagebg.y=image->h / 2 - 50;
        int x=0,y,c=0;
        SDL_BlitSurface(image, NULL, screen, &bgpos);
        SDL_BlitSurface( t[c] ,NULL, screen, &imagebg );
        SDL_Flip(screen);
        SDL_Event event;
        while(1)
        {
                time = SDL_GetTicks();
                while(SDL_PollEvent(&event))
                {
                  SDL_WaitEvent(&event);

                  switch(event.type)
                          {
                                  case SDL_QUIT:
                                          return 0;
                                          break;
                                case SDL_MOUSEMOTION:
                                      x = event.motion.x;
                                        y = event.motion.y;
                                                if(x>=300 && x<=500 && y>=250 && y<=290)
                                                {
                                                  SDL_BlitSurface( t[1] ,NULL, screen, &imagebg );
                                                   c=1;
                                                }
                                                if(x>=300 && x<=500 && y>=300 && y<=340)
                                                {
                                                    SDL_BlitSurface( t[2] ,NULL, screen, &imagebg );
                                                     c=2;
                                                }
                                                if(x>=300 && x<=500 && y>=360 && y<=400)
                                                {
                                                    SDL_BlitSurface( t[3] ,NULL, screen, &imagebg );
                                                     c=3;
                                                }
                                                if(x>=300 && x<=500 && y>=400 && y<=450)
                                                {
                                                    SDL_BlitSurface( t[4] ,NULL, screen, &imagebg );
                                                     c=4;
                                                }
                                                break;
                                case SDL_MOUSEBUTTONDOWN:
                                          x = event.button.x;
                                        y = event.button.y;
                                        if (event.button.button == SDL_BUTTON_LEFT) {
                                if(x>=300 && x<=500 && y>=250 && y<=290)
                                {
                       return 1;
                         break;
                                }
                                if(x>=300 && x<=500 && y>=300 && y<=340)
                                {
                                  return 2;
                                  break;
                                }
                                if(x>=300 && x<=500 && y>=360 && y<=400)
                                {
                                op= optionsmenu(screen,t1,image, imagebg , font,op);
                              SDL_BlitSurface(image, NULL, screen, &bgpos);
                                break;
                                }
                                if(x>=300 && x<=500 && y>=400 && y<=450)
                                {
                                  return 0;
                                  break;
                                }
                                }
                                break;
                        /*        case  SDL_KEYDOWN :

                        if(event.key.keysym.sym == SDLK_RIGHT)
                      {
                     if(c<5)
                         c=c+1;
                       }
                 if(event.key.keysym.sym == SDLK_LEFT)
                     {
                     if(c>1)
                         c=c-1;
                    }
                    else if (((event.key.keysym.sym == SDLK_KP_ENTER)||(event.key.keysym.sym == SDLK_RETURN)))
                   switch (c) {
                     case 1:
                     return 1 ;
                     break;
                     case 2 :
                     return 2 ;
                     break;
                     case 3 :
                     op= optionsmenu(screen,t1, imagebg , font,op);
                 break;
                 case 4 : return 0; break;

                   }
                 break;*/
    }

                    SDL_Flip(screen);
                  //  if(100/30 > (SDL_GetTicks()-time))
                            //SDL_Delay(100/30 - (SDL_GetTicks()-time));
        }
}
}
int  main() {
  char pause;
  int l=0;
   SDL_Init(SDL_INIT_VIDEO);
   TTF_Init();

   TTF_Font *font = NULL;
   font =TTF_OpenFont("arial_narrow_7.ttf", 36);



   if (SDL_Init(SDL_INIT_VIDEO)!=0)
   {printf("unable to initialize SDL : %s\n",SDL_GetError());
   return 1;
   }
   SDL_Surface *screen, *image, *WinImg;
  screen = SDL_SetVideoMode(800, 600, 32,SDL_DOUBLEBUF |SDL_SWSURFACE);

  if(!screen)
  {
    printf("Unable to set 60*400 video : %s\n",SDL_GetError() );
    return (-1);
    }
        SDL_WM_SetCaption("test1", NULL);
        SDL_Rect positionecran ,posdetec,frame,positionwin;  // rect to describe the source desr region of our blit
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
        {
          printf("music error%s\n",Mix_GetError() );

        }
      Mix_Music *music;
        music = Mix_LoadMUS("Menu/intro.wav");
      //  Mix_VolumeChunk(music, MIX_MAX_VOLUME/4);

       Mix_PlayMusic(music,-1);
    // load the bit map into image surface & check
  image = IMG_Load("background.png");// or IMG_Load
  WinImg = IMG_Load("win.png");// or IMG_Load

  SDL_Surface* t[5];
  t[0]=IMG_Load("Menu/menu.png");
  t[1]=IMG_Load("Menu/playon.png");
  t[2]=IMG_Load("Menu/loadgameon.png");
  t[3]=IMG_Load("Menu/optionson.png");
  t[4]=IMG_Load("Menu/quiton.png");
  SDL_Surface* t1[8];
  t1[0]=IMG_Load("Menu/o1.png");
  t1[1]=IMG_Load("Menu//o2.png");
  t1[2]=IMG_Load("Menu/o3.png");
  t1[3]=IMG_Load("Menu/o4.png");
  t1[4]=IMG_Load("Menu/o5.png");
  t1[5]=IMG_Load("Menu/o6.png");
  t1[6]=IMG_Load("Menu/7.png");
  t1[7]=IMG_Load("Menu/o8.png");


  SDL_Rect imagebg;
  imagebg.x = 0;
  imagebg.y = 0;
  if (image == NULL) {
    printf( " ERROR %s\n",SDL_GetError());
    return 1;
  }
  positionecran.x = 0;
  positionecran.y = 0;
  positionecran.w = 800;
  positionecran.h =image->h;
  positionwin.x = 0;
  positionwin.y = 0;
  positionwin.w = WinImg->w;
  positionwin.h =WinImg->h;
    SDL_BlitSurface(image, NULL, screen, &positionecran);
    SDL_Flip(screen);
     int CurFrame =0, MaxFrame = 8;
    SDL_Surface *caractere;
    caractere= IMG_Load("movements.png");
    if (caractere == NULL) {
      printf( " ERROR  caractere %s\n",SDL_GetError());
      return 1;
    }
        posdetec.x=0;
    posdetec.y=350;
    posdetec.h =32;
    posdetec.w =32;
    frame.x=0;
    frame.y=0;
    frame.w=32;
    frame.h=32;
   int r =showmenu(screen, t,image,imagebg,font,t1);
    SDL_Event event;
    while(r==1)
    {
      SDL_BlitSurface(caractere,&frame,screen,&posdetec);
      SDL_Flip(screen);
      while(SDL_PollEvent(&event))
       {

SDL_WaitEvent(&event);
switch (event.type) {
  case SDL_QUIT  : r=0 ; break;
  case SDL_KEYDOWN :
  if (event.key.keysym.sym == SDLK_ESCAPE)
  {
    r=0;
    break;
  }
  if (event.key.keysym.sym == SDLK_RIGHT)
  {
    posdetec.x += 80;
    CurFrame ++ ;
    if (CurFrame > MaxFrame) {
      CurFrame =0;
    }
    frame.x=CurFrame * frame.w;

  }
  if (event.key.keysym.sym == SDLK_LEFT)
  {
    posdetec.x -= 80;

  }
  if (event.key.keysym.sym == SDLK_UP)
  {
    posdetec.y -= 80;

  }
  if (event.key.keysym.sym == SDLK_DOWN)
  {
    posdetec.y += 80;

  }
break;
}
if (posdetec.x > 800) {
  posdetec.x = 0;
  positionecran.x=positionecran.w;
}

SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));

SDL_BlitSurface(caractere,&frame,screen,&posdetec);
SDL_BlitSurface(image, &positionecran, screen, NULL);
SDL_Flip(screen);




}

    }
    SDL_FreeSurface(t[r]);

    SDL_FreeSurface(caractere);

    SDL_FreeSurface(image);

    //Mix_FreeMusic(music);
        TTF_Quit();
                SDL_Quit();
  return 0;
}
