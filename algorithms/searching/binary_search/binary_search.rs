use std::cmp::Ordering;

pub fn binary_search<T: Copy + Ord, C: AsRef<[T]>>(items: C, key: T) -> Option<usize> {
    let mut low = 0;
    let mut high = items.as_ref().len() as isize - 1;

    while low <= high {
        let middle = (high + low) / 2;
        if let Some(current) = items.as_ref().get(middle as usize) {
            match current.cmp(&key) {
                Ordering::Less => low = middle + 1,
                Ordering::Greater => high = middle - 1,
                Ordering::Equal => return Some(middle as usize),
            }
        }
    }

    None
}

/// Implementation for partially orderable elements (e.g. floats)
pub fn binary_search_f<T: Copy + PartialOrd, C: AsRef<[T]>>(items: C, key: T) -> Option<usize> {
    let mut low = 0;
    let mut high = items.as_ref().len() as isize - 1;

    while low <= high {
        let middle = (high + low) / 2;
        if let Some(current) = items.as_ref().get(middle as usize) {
            match current.partial_cmp(&key) {
                None => return None, // Element ordering not possible, return None
                Some(c) => match c {
                    Ordering::Less => low = middle + 1,
                    Ordering::Greater => high = middle - 1,
                    Ordering::Equal => return Some(middle as usize),
                }
            }
        }
    }

    None
}
