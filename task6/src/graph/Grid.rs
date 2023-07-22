use std::collections::HashMap;

use super::Primitive::Point;

pub struct graph_assemble
{
    pub w:usize,
    pub h:usize,
    pub g:Vec<Vec<bool>>,
    pub dist: HashMap<String, Vec<Vec<usize>> >,
}

impl graph_assemble{
    pub fn new(w:usize,h:usize)->Self
    {
        Self{
            w: w,
            h: h,
            g: vec![vec![true; w + 2]; h + 2],
            dist: HashMap::new(),
        }
    }
    pub fn init(&mut self)
    {
        let w = self.w;
        let h = self.h;
        self.g = vec![vec![true; w + 2]; h + 2];
        for i in 0..w + 2{
            self.g[0][i] = false;
            self.g[1][i] = false;
            self.g[h + 1][i] = false;
        }
        for i in 0..h + 2{
            self.g[i][0] = false;
            self.g[i][w + 1] = false;
        }
        self.g[1][2] = true;
        self.g[1][w - 1] = true;
        self.g[h][1] = false;
        self.g[h][w] = false;
    }
    pub fn get_dist(&mut self,s:String,pt:Point)
    {
        let dist:Vec<Vec<usize>> = vec![vec![w * h; w + 2]; h + 2];
        dist[]
    }








    pub fn printGraph(&self)
    {
        for i in 0..self.h + 2{
            for j in 0..self.w + 2{
                print!("{} ",self.g[i][j]);
            }
            println!();
        }
    }
}
