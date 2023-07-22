use std::ops;
use std::cmp::PartialOrd;
use std::cmp::PartialEq;
use std::cmp::Ordering;
#[derive(Eq)]
pub struct Point{
    pub x:usize,
    pub y:usize,
}
impl Point{
    pub fn new(x:usize,y:usize) ->Self
    {
        Self{x,y}
    }
}

pub struct Edge
{
    pub pt:Point,
    pub cost:usize,
}

impl Edge{
    pub fn new(pt:Point,cost:usize) ->Edge
    {
        
        Edge{pt: pt,cost: cost}
    }
}

pub struct Path{
    pub e:Edge,
    pub root:Vec<String>,
}

impl Path{
    pub fn new(e: Edge) ->Path
    {
       Path { e: e,root: Vec::new()}
    }
    pub fn Append(&mut self,s:String)
    {
        self.root.push(s);
    }
}


impl ops::Add<Point> for Point{
    type Output = self;
    fn add(self,others: self)-> self
    {
        self{x: self.x + others.x,y:self.y + others.y}
    }
}

impl PartialEq for Point{
    fn eq(&self, other: &self) -> bool
    {
        self.x == other.x && self.y == other.y
    }
}

impl PartialOrd for Edge{
    fn partial_cmp(&self, other: &self) -> Option<Ordering> {
        if self.cost > other.cost
        {
            Some(Ordering::Greater)
        }
        else if self.cost < other.cost
        {
            Some(Ordering::Less)
        }else{
            None
        }
    }
   
}

impl PartialEq for Edge{
    fn eq(&self, other: &self) -> bool {
        self.cost == other.cost
    }
}


impl PartialOrd for Path{
    fn partial_cmp(&self, other: &self) -> Option<Ordering> 
    {
        if self.e == other.e
        {
            Some(self.root.len().cmp(&other.root.len()))
        }
        else if self.e > other.e
        {
            Some(Ordering::Greater)
        }
        else if self.e < other.e
        {
            Some(Ordering::Less)
        }else{
            None
        }
        
    }
}
impl PartialEq for Path{
    fn eq(&self, other: &self) -> bool {
        self.e == other.e && self.root.len() == other.root.len() 
    }
}
fn main()
{
    let e:Edge;
    let e2:Edge;
    let mut pt:Path;
    let mut pt2:Path;
    e = Edge::new(Point::new(4,4), 4*4);
    e2 = Edge::new(Point::new(5,5),4*4);
    if e < e2 
    {
        println!("e2 is larger");
    }
    else if e > e2
    {
        println!("e is larger");
    }
    else if e == e2
    {
        println!("e and e2 is equal");
    }
    pt = Path::new(e);
    pt2 =Path::new(e2);
    pt.Append("strong".to_string());
    pt.Append("csvfile".to_string());
    pt2.Append("function".to_string());
    if pt > pt2 
    {
        println!("pt is larger");
    }
    else if pt < pt2
    {
        println!("pt2 is larger");
    }
    else if pt == pt2
    {
        println!("pt and pt2 is equal");
    }
    
}





