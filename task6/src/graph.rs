pub mod Grid;
pub mod Primitive;
use Grid::*;
use Primitive::*;


struct Product
{
    name:String,
    pt:Point,
}
impl Product{
    fn new(name:String,pt:Point) ->Self{
        Self { name: name, pt: Point }
    }
}
static products: Vec<Products> = Vec::new();





fn Init(w:usize,h:usize){
    let solve:graph_assemble = graph_assemble::new(w,h);
    graph_assemble::init(graph);
}


fn inputProduct(name:String,x:usize,y:usize,d:char){
    let direct:Vec<Point> = Vec![Point::new(1,0),
                                Point::new(0,1),
                                Point::new(-1,0),
                                Point::new(0,-1)];
    
    match d {
        'E' => x += 1,
        'N' => y += 1,
        'W' => x -= 1,
        'S' => y -= 1,
    }
    
    let p:Product = Product::new(name,Point::new(x,y));
    products.push(p);
}


fn exec()
{
    
}


