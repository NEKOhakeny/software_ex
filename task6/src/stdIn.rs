use std::str::FromStr;
pub struct Input {
    line: Vec<String>,
    position: usize
}
impl Input {
    pub fn new() -> Input {
        Input{line:vec![], position: 0}
    }
    pub fn read_word(&mut self) -> &String {
        if self.position == self.line.len() {
            let mut line= String::new();
            std::io::stdin().read_line(&mut line);
            self.line = line.split_whitespace().map(|x|x.to_string()).collect();
            self.position = 0
        }
        let result = &self.line[self.position];
        self.position += 1;
        result
    }
    pub fn read<T: FromStr>(&mut self, result: &mut T) -> &mut Input {
        *result = self.read_word().parse().ok().unwrap();
        self
    }
    pub fn get<T: FromStr>(&mut self) -> Result<T, T::Err> {
        self.read_word().parse()
    }
}
