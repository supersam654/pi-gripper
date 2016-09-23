# This file allows the contraption to pickup an item.
import hardware_api as api

# QUESTION: How is this getting called?
def main():
    api.position_bottom_plate_on_ground()
    hit_inside_first = api.try_gripping()
    if not hit_inside_first:
        api.retract_claws()
        api.drop_top_plate()
    else:
        api.finish_gripping()
    api.insert_bottom_plate()
    api.lift_arm()

if __name__ == '__main__':
    main()
